#include "musiccontrol.h"
#include <QtMultimedia>

musicControl::musicControl(QObject *parent) : QObject(parent)
{
    shufle = false;
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    currentIndex = 0;
    previousIndex = 0;
    connect(player,SIGNAL(positionChanged(qint64)),this,SIGNAL(newPosition(qint64)));
    connect(player,SIGNAL(durationChanged(qint64)),this,SIGNAL(newRange(qint64)));
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this,SLOT(stateHandler(QMediaPlayer::MediaStatus)));
}

void musicControl::volumeSliderSlot(int value)
{
    player->setVolume(value);
}


void musicControl::setPosition(int position)
{
    player->setPosition(position);
}

void musicControl::stateHandler(QMediaPlayer::MediaStatus state)
{
    switch (state)
    {
    case QMediaPlayer::UnknownMediaStatus:
        break;
    case QMediaPlayer::NoMedia:
        break;
    case QMediaPlayer::LoadingMedia:
        //qDebug()<<"loading media";
        break;
    case QMediaPlayer::LoadedMedia:
        // qDebug()<<"loaded media";
        break;
    case QMediaPlayer::StalledMedia:
        //qDebug()<<"Stalled media";
        break;
    case QMediaPlayer::BufferingMedia:
        //qDebug()<<"Buffering media";
        break;
    case QMediaPlayer::BufferedMedia:
        //qDebug()<<"Buffered media";
        break;
    case QMediaPlayer::EndOfMedia:
        if(shufle)
        {
            int rand;
            QTime time = QTime::currentTime();
            qsrand((uint)time.msec());
            rand = qrand()%playlist->mediaCount();
            playThatSong(rand,0);
        }
        break;
    case QMediaPlayer::InvalidMedia:
        break;
    default:
        break;
    }
}

void musicControl::setPlayList(QList<QUrl> list)
{
    QUrl var;
    foreach (var, list)
    {
        playlist->addMedia(var);
    }
    player->setPlaylist(playlist);
}

void musicControl::playThatSong(int songNumber, int /*secondUnneededParam*/)
{
    //if(currentIndex != 0)
    previousIndex = currentIndex;
    if(!(currentIndex == 0 && previousIndex == 0))   //for reventing extra zero song in prev button
        history.push(previousIndex);
    player->stop();
    playlist->setCurrentIndex(songNumber);
    qDebug()<<playlist->currentMedia().canonicalUrl();
    player->play();
    currentIndex = playlist->currentIndex();
    qDebug()<<"cur: "<<currentIndex<<"    prev: "<<previousIndex;
    qDebug()<<history;
    emit setPlayingUi();
    emit setIndexToUi(currentIndex,previousIndex);
}

void musicControl::setSongIndex(int index, int /*secondUnneededParam*/)
{
    if(player->state() == QMediaPlayer::PausedState)
        playlist->setCurrentIndex(index);
}

void musicControl::shuffleMode(bool enable)
{
    shufle = enable;
}

void musicControl::playNextSong()
{
    if(shufle)
    {
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        currentIndex = qrand()%playlist->mediaCount();
        playlist->setCurrentIndex(currentIndex);
    }
    else
    {
        previousIndex = playlist->currentIndex();
        history.push(previousIndex);
        if(previousIndex != playlist->mediaCount()-1)
            playlist->next();
        currentIndex = playlist->currentIndex();
    }
    qDebug()<<"cur: "<<currentIndex<<"    prev: "<<previousIndex;
    qDebug()<<history;
    emit setIndexToUi(currentIndex,previousIndex);
}

void musicControl::playPrevSong()
{
    int localPreviousIndex;
    localPreviousIndex = playlist->currentIndex();
    if(!history.isEmpty())
    {
        player->stop();
        playlist->setCurrentIndex(history.pop());
        player->play();
    }
    else
        player->play();
    qDebug()<<history;
    emit setIndexToUi(playlist->currentIndex(),localPreviousIndex);
}

void musicControl::changeState()
{
    QMediaPlayer::State state;
    state = player->state();
    switch (state) {
    case QMediaPlayer::PausedState:
        player->play();
        emit setPlayingUi();
        break;
    case QMediaPlayer::PlayingState:
        player->pause();
        emit setPausedUi();
        break;
    default:
        break;
    }
}
