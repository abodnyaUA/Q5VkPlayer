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
    QStack<int> history;
    int selectedSong;
public:
    explicit musicControl(QObject *parent = 0);
    void clearHistory();
signals:
    void setIndexToUi(int,int);
    void setPlayingUi();
    void setPausedUi();
    void newRange(qint64);
    void newPosition(qint64);
public slots:
    void setPlayList(QList<QUrl> list);
    void playThatSong(int,int);
    void shuffleMode(bool);
    void playNextSong();
    void playPrevSong();
    void changeState();
    void volumeSliderSlot(int);
    void setPosition(int position);
    void stateHandler(QMediaPlayer::MediaStatus);
    void setSelectedSong(int,int);
    //void repeatMode(bool);
    
};

#endif // MUSICCONTROL_H
