#ifndef MUSICCONTROL_H
#define MUSICCONTROL_H

#include <QObject>
#include <QtMultimedia>

class musicControl : public QObject
{
    Q_OBJECT
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
public:
    explicit musicControl(QObject *parent = 0);
    
signals:
    
public slots:
    void setPlayList(QList<QUrl> list);
    void playThatSong(int,int);
    
};

#endif // MUSICCONTROL_H
