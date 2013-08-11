#include "vkauth.h"
#include "qdebug.h"
#include "QtGui"
#include <QFile>
#include <QTextStream>
#include <QtXml/QtXml>
#include <QtWebKitWidgets/QWebView>
#include <QUrlQuery>
#include <QMessageBox>

vkAuth::vkAuth(QWidget *parent) : QWebView(parent)
{
    connect(this, SIGNAL(urlChanged(QUrl)), SLOT(slotUrlChanged(QUrl)));
    QUrl url("https://oauth.vk.com/authorize?");
    QUrlQuery turl;
    turl.addQueryItem("client_id", "3652252");  //HERE second param is my app_id, which get from vk.com
    turl.addQueryItem("display", "popup");
    turl.addQueryItem("type", "browser");
    turl.addQueryItem("scope", "audio,offline");
    turl.addQueryItem("redirect_uri", "https://oauth.vk.com/blank.html");
    turl.addQueryItem("response_type", "token");
    url.setQuery(turl);
    qDebug()<<url;
    this->load(url);
    qDebug()<<"default constructor:";
    qDebug()<<url;
}

void vkAuth::slotUrlChanged(QUrl url)
{
    url = url.toString().replace("#","?");
    QUrlQuery qurl;
    qDebug()<<"QUrlQuery creating successful";
    qurl = QUrlQuery(url.query());
    qDebug()<<url;
    if (qurl.hasQueryItem("error"))
    {// in case of unsuccessfull authorisation
        qDebug()<<"vk api returned error statment";
        return ;
    }
    if (!qurl.hasQueryItem("access_token"))
    {
        qDebug()<<"Accsess denided";
        return;
    }
    //creating cookie file
    QFile file("token");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&file);
    //writing token and uid to vodiables
    token = qurl.queryItemValue("access_token");
    expires = qurl.queryItemValue("expires_in").toInt();
    uid = qurl.queryItemValue("user_id");
    //... and to file
    out<<token;
    out<<"\n"<<uid;
    file.close();
    //now we should have an token file
    qDebug()<<"Token file writed";
    qDebug()<<"TOKEN:" << token;
    qDebug()<<"USER_ID:"<<uid;
    qDebug()<<"\n===============login finished==========\n";
    emit tokenSet(token,uid);
    QMessageBox::information(
                this,
                tr("Login successful"),
                tr("You have successfuly log in.") );
   this->deleteLater();
}


vkAuth::~vkAuth()
{
    qDebug()<<"Login window closed";
}
