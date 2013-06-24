#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
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
}

void musicControl::playThatSong(int songNumber, int /*secondUnneededParam*/)
{
    qDebug()<<songNumber;
    playlist->setCurrentIndex(songNumber);
    player->setVolume(50);
    player->play();
}
