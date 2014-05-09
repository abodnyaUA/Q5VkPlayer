#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QMainWindow>
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QByteArray>
#include <QXmlStreamReader>
#include <QAction>
#include <QMenu>
#include <QFile>
#include <QSettings>
#include "vkauth.h"
#include <QMessageBox>
#include <QUrlQuery>
#include <QDebug>
#include "Sources/Model/song.h"

class NetWorker : public QObject
{
    Q_OBJECT
    static NetWorker *__sharedNetworker;
    QNetworkAccessManager *manager;
    QString token;
    QString userId;
    VkAuth *loginWindow;

public:
    static NetWorker *sharedNetworker();
    QString getToken();
    QString getUid();
    void downloadSong(Song *);

signals:
    void didRecieveSongs(QList<Song *>);
    void didDownloadSong(Song *);

public slots:
    void setToken(QString, QString);
    void loginSlot();
    void getAudioList();

private slots:
    void replyFinished(QNetworkReply *reply);
    void songDidDownloaded(QNetworkReply *reply);

private:
    NetWorker();
    NetWorker(const NetWorker&);
    NetWorker& operator=(const NetWorker&);
};

#endif // NETWORKER_H
