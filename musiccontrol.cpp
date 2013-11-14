#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
    selectedSong = 0;
    shufle = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    currentIndex = 0;
    previousIndex = 0;
    connect(player,SIGNAL(positionChanged(qint64)),this,SIGNAL(newPosition(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SIGNAL(newRange(qint64)));
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this,SLOT(stateHandler(QMediaPlayer::MediaStatus)));
}

void musicControl::clearHistory()
{
    history.clear();
}

void musicControl::volumeSliderSlot(int value)
{
    player->setVolume(value);
}


void musicControl::setPosition(int position)
{
    player->setPosition(position);
}

void musicControl::stateHandler(QMediaPlayer::MediaStatus state)
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

void musicControl::setSelectedSong(int index, int /*secondUnneededParam*/)
{
    selectedSong = index;
}

void musicControl::setPlayList(QList<QUrl> list)
{
    QUrl var;
    playlist->clear();
    foreach (var, list)
    {
        playlist->addMedia(var);
    }
    player->setPlaylist(playlist);
}

void musicControl::playThatSong(int songNumber, int /*secondUnneededParam*/)
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

void musicControl::shuffleMode(bool enable)
{
    shufle = enable;
}

void musicControl::playNextSong()
{
    if(shufle)
    {
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        currentIndex = qrand()%playlist->mediaCount();
        playlist->setCurrentIndex(currentIndex);
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

void musicControl::playPrevSong()
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

void musicControl::changeState()
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
