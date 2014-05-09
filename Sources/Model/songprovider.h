#ifndef SONGPROVIDER_H
#define SONGPROVIDER_H

#include <QObject>
#include <QList>
#include <QStringList>
#include "Sources/Model/song.h"

#ifdef WIN32
    #define SLASH "\\"
#else
    #define SLASH "/"
#endif

class SongProvider : public QObject
{
    Q_OBJECT
    static SongProvider *__sharedProvider;
    QList<Song *> songs;
    QStringList localSongs;
    ~SongProvider();
    void updateFromLocalCopy();
public:
    static SongProvider *sharedProvider();
    Song *songWithIndex(quint16 index);
    QList<Song *> songsWithTitleContains(QString searchPart);
    quint16 songsCount();
    QString musicFolderPath();

signals:
    void songListDidUpdated();

public slots:
    void updateSongList(QList<Song *>);

private slots:
    void didDownloadSong(Song *song);

private:
    SongProvider(QObject *parent = 0);
    SongProvider(const SongProvider&);
    SongProvider& operator=(const SongProvider&);
};

#endif // SONGPROVIDER_H
