#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
    shufle = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    currentIndex = 0;
    previousIndex = 0;
    connect(player,SIGNAL(positionChanged(qint64)),this,SIGNAL(newPosition(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SIGNAL(newRange(qint64)));
}

void musicControl::volumeSliderSlot(int value)
{
    player->setVolume(value);
}


void musicControl::setPosition(int position)
{
    player->setPosition(position);
}

void musicControl::setPlayList(QList<QUrl> list)
{
    int len;
    len = list.count();
    for(int i=0;i<len;i++)
    {
        playlist->addMedia(list[i]);
    }
    player->setPlaylist(playlist);
}

void musicControl::playThatSong(int songNumber, int /*secondUnneededParam*/)
{
    if(currentIndex != 0)
        previousIndex = currentIndex;
    player->stop();
    playlist->setCurrentIndex(songNumber);
    player->play();
    currentIndex = playlist->currentIndex();
    qDebug()<<"Current index: "<<currentIndex;
    qDebug()<<"Previous index: "<<previousIndex;
    emit setPlayingUi();
    emit setIndexToUi(currentIndex,previousIndex);
}

void musicControl::setSongIndex(int index, int /*secondUnneededParam*/)
{
    if(player->state() == QMediaPlayer::PausedState)
        playlist->setCurrentIndex(index);
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
        currentIndex = qrand()%playlist->mediaCount();
        playlist->setCurrentIndex(currentIndex);
    }
    else
    {
        previousIndex = playlist->currentIndex();
        if(previousIndex != playlist->mediaCount()-1)
            playlist->next();
        currentIndex = playlist->currentIndex();
    }
    emit setIndexToUi(currentIndex,previousIndex);
}

void musicControl::playPrevSong()
{
    playlist->previous();
    emit setIndexToUi(playlist->currentIndex(),playlist->nextIndex());
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
    default:
        break;
    }
}
