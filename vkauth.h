#ifndef VKAUTH_H
#define VKAUTH_H

#include <QtWebKitWidgets/QWebView>

class VkAuth : public QWebView
{
    Q_OBJECT
public:
    explicit VkAuth(QWidget *parent = 0);
    QString token;
    QString uid;
    ~VkAuth();
private:
    int expires;
signals:
    void tokenSet(QString,QString);
public slots:
    void slotUrlChanged(QUrl);
private slots:

};
#endif // VKAUTH_H
