#include "musiccontrol.h"
#include <QtMultimedia>

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
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this,SLOT(stateHandler(QMediaPlayer::MediaStatus)));
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
    player->setPosition(position);
}

void MusicControl::stateHandler(QMediaPlayer::MediaStatus state)
{
    switch (state)
    {
    case QMediaPlayer::UnknownMediaStatus:
        break;
    case QMediaPlayer::NoMedia:
        break;
    case QMediaPlayer::LoadingMedia:
        //qDebug()<<"loading media";
        break;
    case QMediaPlayer::LoadedMedia:
        // qDebug()<<"loaded media";
        break;
    case QMediaPlayer::StalledMedia:
        //qDebug()<<"Stalled media";
        break;
    case QMediaPlayer::BufferingMedia:
        //qDebug()<<"Buffering media";
        break;
    case QMediaPlayer::BufferedMedia:
        //qDebug()<<"Buffered media";
        break;
    case QMediaPlayer::EndOfMedia:
        playNextSong();
        break;
    case QMediaPlayer::InvalidMedia:
        break;
    default:
        break;
    }
}

void MusicControl::setSelectedSong(int index, int /*secondUnneededParam*/)
{
    qDebug()<<"selected song index: "<<index;
    selectedSong = index;
}

void MusicControl::repeatMode(bool)
{
}

void MusicControl::setPlayList(QList<QUrl> list)
{
    QUrl var;
    playlist->clear();
    foreach (var, list)
    {
        playlist->addMedia(var);
    }
    player->setPlaylist(playlist);
}

void MusicControl::playThatSong(int songNumber, int /*secondUnneededParam*/)
{
    //if(currentIndex != 0)
    previousIndex = currentIndex;
    if(!(currentIndex == 0 && previousIndex == 0))   //for reventing extra zero song in prev button
        history.push(previousIndex);
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
}

void MusicControl::playNextSong()
{
    if(shufle)
    {
        player->stop();
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        if(repeat != true)
            currentIndex = qrand()%playlist->mediaCount();
        else
            currentIndex = playlist->currentIndex();
        playlist->setCurrentIndex(currentIndex);
        player->play();
    }
    else
    {
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        if(previousIndex != playlist->mediaCount()-1)
            playlist->next();
        currentIndex = playlist->currentIndex();
    }
    emit setIndexToUi(currentIndex,previousIndex);
}

void MusicControl::playPrevSong()
{
    int localPreviousIndex;
    localPreviousIndex = playlist->currentIndex();
    if(!history.isEmpty())
    {
        player->stop();
        playlist->setCurrentIndex(history.pop());
        player->play();
    }
    else
        player->play();
    emit setIndexToUi(playlist->currentIndex(),localPreviousIndex);
}

void MusicControl::changeState()
{
    QMediaPlayer::State state;
    state = player->state();
    switch (state) {
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
