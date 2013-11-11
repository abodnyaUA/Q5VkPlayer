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
#include <QSettings>
#include <QSystemTrayIcon>



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
    QSystemTrayIcon *trayIcon;
    void closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void loginSlot();
    void getAudioList();
    void setSongUi(int, int);
    void setPlayingUi();
    void setPausedUi();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void offlineDebugFunction();
private slots:
    void replyFinished(QNetworkReply *reply);
    void setToken(QString,QString);
    void currentSearch(QString text);
    void about();
    void fullExit();
    void trayHandler(QSystemTrayIcon::ActivationReason reason);
    
private:
    Ui::MainWindow *ui;
    QSettings *settings;
    void loadSettings();
    void saveSettings();
signals:
    void setPlayingOrder(QList<QUrl>);
};

#endif // MAINWINDOW_H
