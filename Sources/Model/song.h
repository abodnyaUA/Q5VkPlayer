#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QUrl>

class Song : public QObject
{
    Q_OBJECT
public:
    explicit Song(QObject *parent = 0);
    QString artist;
    QString title;
    QString duration;
    QUrl url;
signals:

public slots:

};

#endif // SONG_H
