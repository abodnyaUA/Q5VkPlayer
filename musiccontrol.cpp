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

void musicControl::setPlayList(QList<QUrl> list)
{
    int len;
    len = list.count();
    for(int i=0;i<len;i++)
    {
        playlist->addMedia(list[i]);
    }
    player->setPlaylist(playlist);
//    playlist->  somewere here must be an good shuffle mode;)
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

    switch(enable)
    {
    case true:
        qDebug()<<"Set random mode";
       // shuffle = true;
        qsrand(QTime::currentTime().msecsTo(QTime()));
        playlist->setPlaybackMode(QMediaPlaylist::Random);
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
    playlist->next();
    emit setIndexToUi(playlist->currentIndex(),playlist->previousIndex());
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
