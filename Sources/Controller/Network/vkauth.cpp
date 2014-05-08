#include "vkauth.h"
#include "qdebug.h"
#include "QtGui"
#include <QFile>
#include <QTextStream>
#include <QtXml/QtXml>
#include <QtWebKitWidgets/QWebView>
#include <QUrlQuery>
#include <QMessageBox>

VkAuth::VkAuth(QWidget *parent) : QWebView(parent)
{
    connect(this, SIGNAL(urlChanged(QUrl)), SLOT(slotUrlChanged(QUrl)));
    QUrl url("https://oauth.vk.com/authorize?");
    QUrlQuery urlQuery;
    urlQuery.addQueryItem("client_id", "3652252");  //HERE second param is my app_id, which get from vk.com
    urlQuery.addQueryItem("display", "popup");
    urlQuery.addQueryItem("type", "browser");
    urlQuery.addQueryItem("scope", "audio,offline");
    urlQuery.addQueryItem("redirect_uri", "https://oauth.vk.com/blank.html");
    urlQuery.addQueryItem("response_type", "token");
    url.setQuery(urlQuery);
    qDebug()<<url;
    this->load(url);
    qDebug()<<"default constructor:";
    qDebug()<<url;
}

void VkAuth::slotUrlChanged(QUrl url)
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
    //writing token and uid to variables
    token = qurl.queryItemValue("access_token");
    expires = qurl.queryItemValue("expires_in").toInt();
    uid = qurl.queryItemValue("user_id");
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


VkAuth::~VkAuth()
{
    qDebug()<<"Login window closed";
}
