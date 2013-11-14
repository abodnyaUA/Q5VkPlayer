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


class netWorker : public QObject
{
    Q_OBJECT
    QList<QStringList> songsTable;
    QList<QUrl> songsList;
    QString token;
    QString userId;
    QStringList tableLine;
public:
    explicit netWorker(QObject *parent = 0);
    QString getToken();
    QString getUid();

signals:
    void audioListGet(QList<QUrl>);
    void dataGot();
public slots:
    QList<QStringList> getSongsTable();
    QList<QUrl> getSongsList();
    void replyFinished(QNetworkReply *reply);
    void setToken(QString,QString);
    void loginSlot();
    void getAudioList();
};

#endif // NETWORKER_H
