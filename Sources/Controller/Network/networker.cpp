#include "networker.h"
#include <QMetaType>

NetWorker *NetWorker::__sharedNetworker = NULL;

NetWorker *NetWorker::sharedNetworker()
{
    if (NULL == NetWorker::__sharedNetworker)
    {
        NetWorker::__sharedNetworker = new NetWorker();
    }
    return NetWorker::__sharedNetworker;
}

QString NetWorker::getToken()
{
    return token;
}

QString NetWorker::getUid()
{
    return userId;
}

void NetWorker::replyFinished(QNetworkReply *reply)
{
    QList<Song *> songsList;
    Song *song = NULL;
    uint number = 0;
    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug()<<"Audio list get";
        QXmlStreamReader xml(reply);
        //qDebug()<<reply->readAll();
        while (!xml.atEnd() && !xml.hasError())
        {
            if (NULL == song)
            {
                song = new Song();
            }
            /* Read next element.*/
            QXmlStreamReader::TokenType token = xml.readNext();
            /* If token is just StartDocument, we'll go to next.*/
            if (token == QXmlStreamReader::StartDocument)
            {
                if (NULL != song)
                {
                    delete song;
                    song = NULL;
                }
                continue;
            }
            /* If token is StartElement, we'll see if we can read it.*/
            else if (token == QXmlStreamReader::StartElement)
            {
                /* If it's named persons, we'll go to the next.*/
                if (xml.name() != "audio")
                {
                    /* If it's named person, we'll dig the information from there.*/
                    if (xml.name() == "artist")
                    {
                        song->artist = xml.readElementText();
                        song->artist[0] = song->artist[0].toUpper();
                    }

                    else if (xml.name() == "title")
                    {
                        song->title = xml.readElementText();
                        song->title[0] = song->title[0].toUpper();
                    }

                    else if (xml.name() == "duration")
                    {
                        song->duration = xml.readElementText().toUInt();
                    }

                    else if (xml.name() == "url")
                    {
                        song->url = QUrl(xml.readElementText());
                        song->number = number++;
                        songsList.append(song);
                        song = NULL;
                    }
                }
            }
        }
        /* Error handling. */
        if (xml.hasError())
        {
            QMessageBox::critical(qApp->activeWindow(), "XML ERROR", xml.errorString(), QMessageBox::Ok);
        }
        /* Removes any device() or data from the reader and resets its internal state to the initial state. */
        xml.clear();
    }
    else
    {
        qDebug()<<reply->errorString();
    }
    emit didRecieveSongs(songsList);
    qDebug()<<"reply finished";
}

void NetWorker::loginSlot()
{
    loginWindow = new VkAuth;
    QObject::connect(loginWindow,SIGNAL(tokenSet(QString,QString)),SLOT(setToken(QString,QString)));
    loginWindow->show();
    qDebug()<<"Login window loaded.....";
}

void NetWorker::getAudioList()
{
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

void NetWorker::setToken(QString value,QString value2)
{
    token = value;
    userId = value2;
    qDebug()<<"token: "<<token<<"      UID: "<<userId;
    if (token == "none" || token == "")
    {
        this->loginSlot();
    }
}
