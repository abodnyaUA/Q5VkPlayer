#include "networker.h"
#include <QMetaType>
#include <QDir>
#include "Sources/Model/songprovider.h"

NetWorker *NetWorker::__sharedNetworker = NULL;

NetWorker *NetWorker::sharedNetworker()
{
    if (NULL == NetWorker::__sharedNetworker)
    {
        NetWorker::__sharedNetworker = new NetWorker();
    }
    return NetWorker::__sharedNetworker;
}

NetWorker::NetWorker()
{
    this->manager = new QNetworkAccessManager();
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
    disconnect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
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
                        song->artist = xml.readElementText().replace("&amp;","&");
                        song->artist[0] = song->artist[0].toUpper();
                    }

                    else if (xml.name() == "title")
                    {
                        song->title = xml.readElementText().replace("&amp;","&");
                        song->title[0] = song->title[0].toUpper();
                    }

                    else if (xml.name() == "duration")
                    {
                        song->duration = xml.readElementText().toUInt();
                    }

                    else if (xml.name() == "url")
                    {
                        song->url = QUrl(xml.readElementText().split("?")[0]);
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
    QNetworkAccessManager *manager = this->manager;
    connect(manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
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

#pragma mark - Downloading

void NetWorker::downloadSong(Song *song)
{
    QUrl url(song->url);
    qDebug() << "start downloading song with url "<< url;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(song->number));

    QNetworkAccessManager *manager = this->manager;
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(songDidDownloaded(QNetworkReply*)));
    manager->get(request);
}

void NetWorker::songDidDownloaded(QNetworkReply *reply)
{
    disconnect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(songDidDownloaded(QNetworkReply*)));
    QString musicDirectory = SongProvider::sharedProvider()->musicFolderPath();
    int songIndex = reply->request().header(QNetworkRequest::ContentDispositionHeader).toInt();
    Song *song = SongProvider::sharedProvider()->songWithIndex(songIndex);
    song->local = true;
    QString fileName = song->fullName();
    QString filePath = musicDirectory + fileName + ".mp3";
    qDebug() << "FINISH DOWNLOADING FILE " << filePath;
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly))
    {
        QByteArray data = reply->readAll();
        file.write(data);
        file.flush();
        file.close();
        emit didDownloadSong(song);
    }
}
