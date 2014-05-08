#ifndef MUSICCONTROL_H
#define MUSICCONTROL_H

#include <QObject>
#include <QtMultimedia>


class MusicControl : public QObject
{
    Q_OBJECT
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    bool shufle;
    bool repeat;
    int currentIndex;
    int previousIndex;
    QStack<int> history;
    int selectedSong;
public:
    explicit MusicControl(QObject *parent = 0);
    void clearHistory();
signals:
    void setIndexToUi(int,int);
    void setPlayingUi();
    void setPausedUi();
    void newRange(qint64);
    void newPosition(qint64);
public slots:
    void updatePlayList();
    void playThatSong(int,int);
    void shuffleMode(bool);
    void playNextSong();
    void playPrevSong();
    void changeState();
    void volumeSliderSlot(int);
    void setPosition(int position);
    void stateHandler(QMediaPlayer::MediaStatus);
    void setSelectedSong(int,int);
    void repeatMode(bool);
    
};

#endif // MUSICCONTROL_H
