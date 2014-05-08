#include "songprovider.h"
#include "Sources/Controller/Network/networker.h"

SongProvider *SongProvider::__sharedProvider = NULL;

SongProvider::SongProvider(QObject *parent) : QObject(parent)
{
    connect(NetWorker::sharedNetworker(), SIGNAL(didRecieveSongs(QList<Song *>)), this, SLOT(updateSongList(QList<Song *>)));
}

SongProvider *SongProvider::sharedProvider()
{
    if (NULL == SongProvider::__sharedProvider)
    {
        SongProvider::__sharedProvider = new SongProvider();
    }
    return SongProvider::__sharedProvider;
}

void SongProvider::updateSongList(QList<Song *> songs)
{
    this->songs = songs;
    emit this->songListDidUpdated();
}

Song *SongProvider::songWithIndex(quint16 index)
{
//    assert(index < this->songs.count());
    return this->songs.at(index);
}

quint16 SongProvider::songsCount()
{
    return this->songs.count();
}
