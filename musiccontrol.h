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
    int currentIndex;
    int previousIndex;
public:
    explicit musicControl(QObject *parent = 0);
    
signals:
    void setIndexToUi(int,int);
    void setPlayingUi();
    void setPausedUi();
    void newRange(qint64);
    void newPosition(qint64);
public slots:
    void setPlayList(QList<QUrl> list);
    void playThatSong(int,int);
    void setSongIndex(int,int);
    void shuffleMode(bool);
    void playNextSong();
    void playPrevSong();
    void changeState();
    void volumeSliderSlot(int);
    void setPosition(int position);
    //void repeatMode(bool);
    
};

#endif // MUSICCONTROL_H
