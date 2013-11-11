#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QByteArray>
#include <QXmlStreamReader>
#include <QAction>
#include <QMenu>
#include <QFile>
#include <QSettings>


class netWorker : public QObject
{
    Q_OBJECT
public:
    explicit netWorker(QObject *parent = 0);

signals:

public slots:

};

#endif // NETWORKER_H
