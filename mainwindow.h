#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QByteArray>
#include "vkauth.h"
#include <QXmlStreamReader>
#include <QAction>
#include <QMenu>
#include <QFile>
#include "musiccontrol.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString token;
    QString userId;
    QStringList tableLine;
    QList<QUrl> linkList;
    QString durationToHuman(int d);
    void setTableLine(QStringList line);
    musicControl *music;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void loginSlot();
    void getAudioList();
    void setSongUi(int,int);
    void setPlayingUi();
    void setPausedUi();
    void setSuffle();
private slots:
    void replyFinished(QNetworkReply *reply);
    void setToken(QString,QString);
    void about();
    
private:
    Ui::MainWindow *ui;
signals:
    void setPlayingOrder(QList<QUrl>);
};

#endif // MAINWINDOW_H
