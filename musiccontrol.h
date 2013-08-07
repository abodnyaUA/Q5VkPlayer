#ifndef MUSICCONTROL_H
#define MUSICCONTROL_H

#include <QObject>
#include <QtMultimedia>

class musicControl : public QObject
{
    Q_OBJECT
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    bool shufle;
public:
    explicit musicControl(QObject *parent = 0);
    
signals:
    void setIndexToUi(int,int);
    void setPlayingUi();
    void setPausedUi();
public slots:
    void setPlayList(QList<QUrl> list);
    void playThatSong(int,int);
    void setSongIndex(int,int);
    void shuffleMode(bool);
    void playNextSong();
    void playPrevSong();
    void changeState();
    //void repeatMode(bool);
    
};

#endif // MUSICCONTROL_H
