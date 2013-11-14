#include "networker.h"

netWorker::netWorker(QObject *parent) : QObject(parent)
{
    songsList.clear();
    songsTable.clear();
}

QString netWorker::getToken()
{
    return token;
}

QString netWorker::getUid()
{
    return userId;
}

QList<QStringList> netWorker::getSongsTable()
{
    return songsTable;
}

QList<QUrl> netWorker::getSongsList()
{
    return songsList;
}

void netWorker::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug()<<"Audio list get";
        QXmlStreamReader xml(reply);
        while(!xml.atEnd() && !xml.hasError())
        {
            /* Read next element.*/
            QXmlStreamReader::TokenType token = xml.readNext();
            /* If token is just StartDocument, we'll go to next.*/
            if(token == QXmlStreamReader::StartDocument)
            {
                continue;
            }
            /* If token is StartElement, we'll see if we can read it.*/
            if(token == QXmlStreamReader::StartElement)
            {
                /* If it's named persons, we'll go to the next.*/
                if(xml.name() == "audio")
                {
                    tableLine.clear();
                    continue;
                }
                /* If it's named person, we'll dig the information from there.*/
                if(xml.name() == "artist")
                {
                    tableLine.append(xml.readElementText());
                }
                if(xml.name() == "title")
                {
                    tableLine.append(xml.readElementText());
                }
                if(xml.name() == "duration")
                {
                    tableLine.append(xml.readElementText());
                }
                if(xml.name() == "url")
                {
                    QString line = xml.readElementText();
                    tableLine.append(line);
                    songsList.append(QUrl(line));
                    songsTable.append(tableLine);
                }

            }
        }
        /* Error handling. */
        if(xml.hasError())
        {
            QMessageBox::critical(qApp->activeWindow(),
                                  "XML ERROR",
                                  xml.errorString(),
                                  QMessageBox::Ok);
        }
        /* Removes any device() or data from the reader
                * and resets its internal state to the initial state. */
        xml.clear();
    }
    else
    {
        qDebug()<<reply->errorString();
    }
    emit audioListGet(songsList);
    emit dataGot();
    songsList.clear();
    qDebug()<<"reply finished";
}

void netWorker::loginSlot()
{
    vkAuth *loginWindow = new vkAuth;
    QObject::connect(loginWindow,SIGNAL(tokenSet(QString,QString)),SLOT(setToken(QString,QString)));
    loginWindow->show();
    qDebug()<<"Login window loaded.....";
}

void netWorker::getAudioList()
{
    songsList.clear();
    songsTable.clear();
    QUrl rAudioUrl("https://api.vk.com/method/audio.get.xml?");
    QUrlQuery tmpUrl;
    tmpUrl.addQueryItem("uid", userId);
    tmpUrl.addQueryItem("access_token", token);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),SLOT(replyFinished(QNetworkReply*)));
    rAudioUrl.setQuery(tmpUrl);
    //qDebug()<<rAudioUrl;
    manager->get(QNetworkRequest(rAudioUrl));
}

void netWorker::setToken(QString value,QString value2)
{
    token = value;
    userId = value2;
    qDebug()<<"token: "<<token<<"      UID: "<<userId;
    if(token == "none" || token == "")
        this->loginSlot();
}
