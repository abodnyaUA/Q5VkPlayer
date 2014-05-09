#ifndef SONGPROVIDER_H
#define SONGPROVIDER_H

#include <QObject>
#include <QList>
#include "Sources/Model/song.h"

class SongProvider : public QObject
{
    Q_OBJECT
    static SongProvider *__sharedProvider;
    QList<Song *> songs;
    ~SongProvider();
public:
    static SongProvider *sharedProvider();
    Song *songWithIndex(quint16 index);
    QList<Song *> songsWithTitleContains(QString searchPart);
    quint16 songsCount();

signals:
    void songListDidUpdated();

public slots:
    void updateSongList(QList<Song *>);

private:
    SongProvider(QObject *parent = 0);
    SongProvider(const SongProvider&);
    SongProvider& operator=(const SongProvider&);
};

#endif // SONGPROVIDER_H
