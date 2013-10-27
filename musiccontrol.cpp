#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
    shufle = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
}

void musicControl::volumeSliderSlot(int value)
{
    player->setVolume(value);
}

void musicControl::shuffleSongs(QList<QUrl> normalList)
{
    int size = normalList.length();
    
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
    qDebug()<<songNumber;
    playlist->setCurrentIndex(songNumber);
    player->play();
    emit setPlayingUi();
}

void musicControl::setSongIndex(int index, int /*secondUnneededParam*/)
{
    if(player->state() == QMediaPlayer::PausedState)
        playlist->setCurrentIndex(index);
}

void musicControl::shuffleMode(bool enable)
{
    shufle = enable;
    switch(enable)
    {
    case true:
        qDebug()<<"Set random mode";
        // shuffle = true;
        //playlist->setPlaybackMode(QMediaPlaylist::Random);
        //playlist->shuffle();
        break;
    case false:
        qDebug()<<"Set normal mode";
        //shuffle = false;
        playlist->setPlaybackMode(QMediaPlaylist::Sequential);
        break;
    }
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
