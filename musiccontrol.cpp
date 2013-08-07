#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
    shufle = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
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
    player->setVolume(50);
    player->play();
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
    qDebug()<<"next song";
    playlist->next();
    qDebug()<<playlist->currentIndex();
    emit setIndexToUi(playlist->currentIndex(),playlist->previousIndex());
}

void musicControl::playPrevSong()
{
    qDebug()<<"Prev song";
    playlist->previous();
    emit setIndexToUi(playlist->currentIndex(),playlist->nextIndex());
    qDebug()<<playlist->currentIndex();
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
