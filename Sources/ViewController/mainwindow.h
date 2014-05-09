#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QMessageBox>
#include <QByteArray>
#include <QXmlStreamReader>
#include <QAction>
#include <QMenu>
#include <QFile>
#include "Sources/Controller/Network/vkauth.h"
#include "Sources/Controller/musiccontrol.h"
#include "Sources/ViewController/prefwindow.h"
#include "Sources/Model/song.h"
#include <QSettings>
#include <QSystemTrayIcon>
#include <QThread>
#include <QMetaType>

#ifdef Q_OS_LINUX
#include <QtDBus/QDBusConnection>
#endif


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStringList tableLine;
    QList<QUrl> linkList;
    QString durationToHuman(int d);
    void addSongInTable(Song *song);
    MusicControl *music;
    QSystemTrayIcon *trayIcon;
    PrefWindow *settingsWindow;
    void closeEvent(QCloseEvent *event);
    QString desktop;
    void loadSettings();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void updateMusicTable();
    void setSongUi(int, int);
    void setPlayingUi();
    void setPausedUi();
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setNewSettings(bool use, bool media, bool cache, bool minTray);
private slots:
    void currentSearch(QString text);
    void updateSearch();
    void about();
    void trayHandler(QSystemTrayIcon::ActivationReason reason);
#ifdef Q_OS_LINUX
    void linuxIconShow();
#endif
private:
    Ui::MainWindow *ui;
signals:
    void loadToken(QString,QString);
    void setPlayingOrder(QList<QUrl>);
    void setPrefWindowsHotkeysUi(bool use, bool media);
    void setMinToTray(bool min);
};

#endif // MAINWINDOW_H
