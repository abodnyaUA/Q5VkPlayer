#ifndef VKAUTH_H
#define VKAUTH_H

#include <QtWebKitWidgets/QWebView>

class vkAuth : public QWebView
{
    Q_OBJECT
public:
    explicit vkAuth(QWidget *parent = 0);
    QString token;
    QString uid;
private:
    int expires;
signals:
    void tokenSet(QString,QString);
public slots:
    void slotUrlChanged(QUrl);
private slots:

};
#endif // VKAUTH_H
