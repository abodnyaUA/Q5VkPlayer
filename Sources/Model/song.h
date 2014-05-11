#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QUrl>

class Song : public QObject
{
    Q_OBJECT
public:
    explicit Song(QObject *parent = 0);
    uint number;
    QString artist;
    QString title;
    uint duration;
    QUrl url;
    bool local;

    QString fullName();
};

#endif // SONG_H
