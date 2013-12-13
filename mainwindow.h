#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
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
#include "networker.h"
#include "prefwindow.h"
#include <QSettings>
#include <QSystemTrayIcon>
#include <QThread>
#include <QMetaType>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStringList tableLine;
    QList<QUrl> linkList;
    QString durationToHuman(int d);
    void setTableLine(QStringList line);
    MusicControl *music;
    QSystemTrayIcon *trayIcon;
    NetWorker *netCore;
    PrefWindow *settingsWindow;
    void closeEvent(QCloseEvent *event);
    bool useHotkeys;
    bool useMediaHotkeys;
    bool useCache;
//    QThread *netWorkThread;
//    QThread *mediaThread;
#ifdef WIN32
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
#endif
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void setMusicTable();
    void setSongUi(int, int);
    void setPlayingUi();
    void setPausedUi();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void offlineDebugFunction();
    void setNewSettings(bool use, bool media, bool cache, QString path);
private slots:
    void currentSearch(QString text);
    void about();
    void trayHandler(QSystemTrayIcon::ActivationReason reason);
    
private:
    Ui::MainWindow *ui;
    QSettings *settings;
    void loadSettings();
    void saveSettings();
signals:
    void loadToken(QString,QString);
    void setPlayingOrder(QList<QUrl>);
    void setPrefWindowsHotkeysUi(bool use, bool media);
};

#endif // MAINWINDOW_H
