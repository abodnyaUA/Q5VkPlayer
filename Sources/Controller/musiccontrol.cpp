#include "musiccontrol.h"
#include <QtMultimedia>
#include "Sources/Prefix/application.h"
#include "Sources/Model/songprovider.h"

MusicControl::MusicControl(QObject *parent) : QObject(parent)
{
    selectedSong = 0;
    shufle = false;
    repeat = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    currentIndex = 0;
    previousIndex = 0;
    connect(player,SIGNAL(positionChanged(qint64)),this,SIGNAL(newPosition(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SIGNAL(newRange(qint64)));
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(stateHandler(QMediaPlayer::MediaStatus)));
    connect(player,SIGNAL(currentMediaChanged(QMediaContent)),this,SLOT(songDidChanged(QMediaContent)));
    connect(SongProvider::sharedProvider(),SIGNAL(songListDidUpdated()),this,SLOT(updatePlayList()));
    connect(qvkApp->hotkeyHandler,SIGNAL(didTapNextButton()),this,SLOT(playNextSong()));
    connect(qvkApp->hotkeyHandler,SIGNAL(didTapPrevButton()),this,SLOT(playPrevSong()));
    connect(qvkApp->hotkeyHandler,SIGNAL(didTapPlayPauseButton()),this,SLOT(changeState()));
}

void MusicControl::clearHistory()
{
    history.clear();
}

void MusicControl::volumeSliderSlot(int value)
{
    player->setVolume(value);
}

void MusicControl::setPosition(int position)
{
    player->pause();
    player->setPosition(position);
    player->play();
}

void MusicControl::stateHandler(QMediaPlayer::MediaStatus state)
{
    qDebug() << "New state of player " <<state;
    switch (state)
    {
    case QMediaPlayer::UnknownMediaStatus:
    case QMediaPlayer::NoMedia:
    case QMediaPlayer::InvalidMedia:
    case QMediaPlayer::EndOfMedia:
        playNextSong();
        break;
    default: break;
    }
}

void MusicControl::songDidChanged(QMediaContent)
{
#ifdef Q_OS_OSX
    if (playlist->currentIndex() >= 0 && playlist->currentIndex() < SongProvider::sharedProvider()->songsCount() && !qvkApp->settings->shuffle)
    {
        qDebug() << "Song did changed to index "<<playlist->currentIndex();
        if (shufle)
        {
            playRandomSong();
        }
        else
        {
            previousIndex = currentIndex;
            history.push(previousIndex);
            currentIndex = playlist->currentIndex();
        }
        emit setIndexToUi(currentIndex,previousIndex);
    }
#endif
}

void MusicControl::selectSongWithIndex(int index)
{
    qDebug()<<"selected song index: "<<index;
    selectedSong = index;
}

void MusicControl::repeatMode(bool)
{
}

void MusicControl::updatePlayList()
{
    playlist->clear();

    SongProvider *songProvider = SongProvider::sharedProvider();
    quint16 songsCount = songProvider->songsCount();
    for (quint16 index = 0; index < songsCount; index++)
    {
        Song *song = songProvider->songWithIndex(index);
        playlist->addMedia(song->url);
    }
    player->setPlaylist(playlist);
}

void MusicControl::playThatSong(int songNumber, int)
{
    qDebug() << "Play song with id:" <<songNumber;
    //if(currentIndex != 0)
    previousIndex = currentIndex;

    //for reventing extra zero song in prev button
    if (currentIndex != 0 || previousIndex != 0)
    {
        history.push(previousIndex);
    }

    player->stop();
    playlist->setCurrentIndex(songNumber);
    player->play();
    currentIndex = playlist->currentIndex();
    emit setPlayingUi();
    emit setIndexToUi(currentIndex,previousIndex);
}

void MusicControl::shuffleMode(bool enable)
{
    shufle = enable;
    qvkApp->settings->shuffle = enable;
}

void MusicControl::playNextSong()
{
    qDebug() << "Play next song";
    if (shufle)
    {
        playRandomSong();
    }
    else
    {
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        if (previousIndex != playlist->mediaCount() - 1)
        {
            playlist->next();
        }
        currentIndex = playlist->currentIndex();
    }
    emit setIndexToUi(currentIndex,previousIndex);
}

void MusicControl::playRandomSong()
{
    player->stop();
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    previousIndex = currentIndex;
    history.push(previousIndex);
    if (!repeat)
    {
        currentIndex = qrand() % playlist->mediaCount();
    }
    else
    {
        currentIndex = playlist->currentIndex();
    }
    playlist->setCurrentIndex(currentIndex);
    player->play();
}

void MusicControl::playPrevSong()
{
    qDebug() << "Play prev song";
    int localPreviousIndex;
    localPreviousIndex = playlist->currentIndex();
    if (!history.isEmpty())
    {
        player->stop();
        playlist->setCurrentIndex(history.pop());
        player->play();
    }
    else
    {
        player->play();
    }
    emit setIndexToUi(playlist->currentIndex(),localPreviousIndex);
}

void MusicControl::changeState()
{
    QMediaPlayer::State state;
    state = player->state();
    switch (state)
    {
    case QMediaPlayer::PausedState:
        player->play();
        emit setPlayingUi();
        break;
    case QMediaPlayer::PlayingState:
        player->pause();
        emit setPausedUi();
        break;
    case QMediaPlayer::StoppedState:
        playThatSong(selectedSong,0);
        emit setPlayingUi();
    default:
        break;
    }
}

int MusicControl::currentSongIndex()
{
    return currentIndex;
}
