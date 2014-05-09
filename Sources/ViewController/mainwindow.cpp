#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Sources/Prefix/application.h"
#include "Sources/Controller/Network/vkauth.h"
#include "Sources/Controller/Network/networker.h"
#include "Sources/Controller/musiccontrol.h"
#include "Sources/Model/songprovider.h"
#include "Sources/Controller/notificationssender.h"
#include <QDebug>
#include <QSettings>
#include <QSystemTrayIcon>
#include <QtConcurrent/QtConcurrent>
#ifdef Q_OS_LINUX
#include "dbus/dbusmethods.h"
#include "dbus/dbusadaptor.h"
#include "dbus/dbusadaptor1.h"
#include <QtDBus/QDBusConnection>
#endif


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    music = new MusicControl;
    settingsWindow = new PrefWindow(this);
    settingsWindow->setWindowFlags(Qt::Dialog);
    ui->lineEdit->setPlaceholderText("Search here");
    ui->seekSlider->setRange(0,0);
    ui->repeatButton->hide();

    ///tray icon setup
    QAction *next = new QAction(tr("Next"), this);
    QAction *restore = new QAction(tr("Show window"), this);
    QAction *prev = new QAction(tr("Previous"), this);
    QAction *playPause = new QAction(tr("Play/Pause"), this);
    QAction *close = new QAction(tr("Exit"), this);

    connect(next,SIGNAL(triggered()),music,SLOT(playNextSong()));
    connect(prev,SIGNAL(triggered()),music,SLOT(playPrevSong()));
    connect(playPause,SIGNAL(triggered()),music,SLOT(changeState()));
    connect(close,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(restore,SIGNAL(triggered()),this,SLOT(show()));

    QMenu *trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(restore);
    trayIconMenu->addAction(next);
    trayIconMenu->addAction(prev);
    trayIconMenu->addAction(playPause);
    trayIconMenu->addAction(close);
    trayIcon = new QSystemTrayIcon(QIcon(":/Resources/Images/appicon/qvk.svg"));
    trayIcon->setContextMenu(trayIconMenu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
            SLOT(trayHandler(QSystemTrayIcon::ActivationReason)));
    //trayIcon->setVisible(true);
    //trayIcon->show();


    ///table setting
    QStringList header;
    ui->musicWidget->setColumnCount(4);
    header <<"Artist"<<"Title"<<"Duration"<<"link";   //in case of unsuccesseful update....
    ui->musicWidget->hideColumn(3);
    ui->musicWidget->setHorizontalHeaderLabels(header);
    ui->musicWidget->verticalHeader()->setVisible(false);
    ui->musicWidget->setShowGrid(false);
    ui->musicWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->musicWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->musicWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->musicWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    ////////////////////////////////////////////////Creating actions
    QAction *login = new QAction(tr("Login"),this);
    QAction *About = new QAction(tr("About"),this);
    QAction *refrsh = new QAction(tr("Refresh"),this);
    QAction *showSettingsWindow = new QAction(tr("Settings"),this);
    connect(showSettingsWindow, SIGNAL(triggered()),settingsWindow,SLOT(show()));
    connect(refrsh,SIGNAL(triggered()), NetWorker::sharedNetworker(), SLOT(getAudioList()));
    connect(login, SIGNAL(triggered()), NetWorker::sharedNetworker(), SLOT(loginSlot()));
    connect(About, SIGNAL(triggered()), this, SLOT(about()));
    ////////////////////////////////////////////////Creating menu
    QMenu *gearButtonMenu = new QMenu("Options", ui->toolButton);
    gearButtonMenu->addAction(refrsh);
    gearButtonMenu->addAction(login);
    gearButtonMenu->addAction(showSettingsWindow);
    gearButtonMenu->addSeparator();
    gearButtonMenu->addAction(About);
    gearButtonMenu->addAction(close);
    ///////////////////////////////////////////////making menu button
    ui->toolButton->setMenu(gearButtonMenu);

    ///connection area
    connect(SongProvider::sharedProvider(),SIGNAL(songListDidUpdated()),this,SLOT(updateMusicTable()));
    connect(ui->volumeSlider,SIGNAL(valueChanged(int)),music,SLOT(volumeSliderSlot(int)));
    connect(ui->volumeSlider,SIGNAL(valueChanged(int)),qvkApp->settings,SLOT(setVolume(int)));
    connect(ui->musicWidget,SIGNAL(cellDoubleClicked(int,int)),music,SLOT(playThatSong(int,int)));
    connect(ui->shuffButton,SIGNAL(toggled(bool)),music,SLOT(shuffleMode(bool)));
    connect(ui->nextButton,SIGNAL(clicked()),music,SLOT(playNextSong()));
    connect(ui->prevButton,SIGNAL(clicked()),music,SLOT(playPrevSong()));
    connect(ui->tooglePlayingButton,SIGNAL(clicked()),music,SLOT(changeState()));
    connect(ui->seekSlider,SIGNAL(sliderMoved(int)),music,SLOT(setPosition(int)));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(currentSearch(QString)));
    connect(ui->musicWidget,SIGNAL(cellClicked(int,int)),music,SLOT(setSelectedSong(int,int)));
    connect(ui->repeatButton,SIGNAL(clicked(bool)),music,SLOT(repeatMode(bool)));
    connect(music,SIGNAL(setIndexToUi(int,int)),this,SLOT(setSongUi(int,int)));
    connect(music,SIGNAL(setPlayingUi()),this,SLOT(setPlayingUi()));
    connect(music,SIGNAL(setPausedUi()),this,SLOT(setPausedUi()));
    connect(music,SIGNAL(newPosition(qint64)),this,SLOT(positionChanged(qint64)));
    connect(music,SIGNAL(newRange(qint64)),this,SLOT(durationChanged(qint64)));
    connect(this,SIGNAL(loadToken(QString,QString)),NetWorker::sharedNetworker(),SLOT(setToken(QString,QString)));
    connect(this,SIGNAL(setPrefWindowsHotkeysUi(bool,bool)),settingsWindow,SLOT(setUseHotkeysUi(bool,bool)));
    connect(this,SIGNAL(setMinToTray(bool)),settingsWindow,SLOT(setUseMinTray(bool)));
    connect(settingsWindow,SIGNAL(setNewSettings(bool,bool,bool,bool)),this,SLOT(setNewSettings(bool,bool,bool,bool)));
    ///connection area

    ///DBUS setting
#ifdef Q_OS_LINUX
    DBusMethods* demo = new DBusMethods();
    new DBusAdaptor(demo);
    new DBusAdaptor1(demo);

    QDBusConnection connection = QDBusConnection::sessionBus();
    bool ret = connection.registerService("org.mpris.MediaPlayer2.qvkplayer.mainwindow");
    ret = connection.registerObject("/org/mpris/MediaPlayer2", demo);
    connect(demo,SIGNAL(dbusNext()),ui->nextButton,SIGNAL(clicked()));
    connect(demo,SIGNAL(dbusPlayPause()),ui->tooglePlayingButton,SIGNAL(clicked()));
    connect(demo,SIGNAL(dbusPrev()),ui->prevButton,SIGNAL(clicked()));
    connect(demo,SIGNAL(dbusQuit()),qApp,SLOT(quit()));
    connect(demo,SIGNAL(dbusRaise()),this,SLOT(show()));
#endif

    ///DBUS setting
    loadSettings();
}

#pragma mark - Settings

void MainWindow::loadSettings()
{
    SettingsController *settings = qvkApp->settings;

    restoreGeometry(settings->geometry);
    ui->volumeSlider->setValue(settings->volume);

    emit loadToken(settings->token,settings->userID);

    NetWorker::sharedNetworker()->getAudioList();

    emit setPrefWindowsHotkeysUi(settings->useHotkeys(), settings->useMediaHotkeys());
    settings->useCache = false;
}

void MainWindow::setNewSettings(bool use, bool media, bool cache, bool minTray)
{
    qDebug()<<use<<" "<<media<<" "<<cache<<" "<<minTray;
    SettingsController *settings = qvkApp->settings;
    settings->setUseHotkeys(use);
    settings->setUseMediaHotkeys(media);
    settings->useCache = cache;
    settings->minToTray = minTray;
    settings->save();
    emit setPrefWindowsHotkeysUi(use, media);
    emit setMinToTray(minTray);
}

#pragma mark - Playing Handler

void MainWindow::setPlayingUi()
{
    ui->tooglePlayingButton->setIcon(QIcon(QPixmap(":/Resources/Images/dark/gtk-media-pause.png")));
}

void MainWindow::setPausedUi()
{
    ui->tooglePlayingButton->setIcon(QIcon(QPixmap(":/Resources/Images/dark/gtk-media-play-ltr.png")));
}

void MainWindow::positionChanged(qint64 position)
{
    ui->seekSlider->setValue(position);
}

void MainWindow::durationChanged(qint64 duration)
{
    ui->seekSlider->setRange(0,duration);
}

void MainWindow::setSongUi(int current,int prev)
{
    qDebug()<<"CHANGE SONG from "<< prev <<" TO "<<current;

    Song *song = SongProvider::sharedProvider()->songWithIndex(current);
    // Notify
    if (current != prev)
    {
        NotificationsSender::sendNotification(song->artist,song->title);
    }

    // Scroll
    if (current < ui->musicWidget->rowCount())
    {
        ui->musicWidget->scrollToItem(ui->musicWidget->item(current,0));
    }

    // Change title
    this->setWindowTitle(song->artist + " - " + song->title);

    // Select
    QFont boldFont;
    boldFont.setBold(true);
    QFont regularFont;
    regularFont.setBold(false);
    for (int column = 0; column < ui->musicWidget->columnCount(); column++)
    {
        if (prev < ui->musicWidget->rowCount())
        {
            ui->musicWidget->item(prev,column)->setSelected(false);
            ui->musicWidget->item(prev,column)->setFont(regularFont);
        }
        if (current < ui->musicWidget->rowCount())
        {
            ui->musicWidget->item(current,column)->setSelected(true);
            ui->musicWidget->item(current,column)->setFont(boldFont);
        }
    }
}

void MainWindow::currentSearch(QString text)
{
    qDebug()<<"USER IS SEARCHING======================================";
    ui->lineEdit->setStyleSheet("QLineEdit{background: #FFFFFF;}");    //white for search line
    qDebug()<<text;
    QList<QTableWidgetItem *> foundList;
    foundList = ui->musicWidget->findItems(text,Qt::MatchContains);
    if (!foundList.isEmpty())
    {
        qDebug()<<"Found at row: " ;
        qDebug()<<foundList[0]->row()+1;
        ui->musicWidget->selectRow(foundList[0]->row());
    }
    else
    {
        ui->lineEdit->setStyleSheet("QLineEdit{background: #FF6666;}");   //error for the searchline
    }
}

QString MainWindow::durationToHuman(int d)
{
    int minutes = d / 60;
    int seconds = d % 60;
    QString out;
#warning time formater
    if (seconds < 10)
    {
        out = QString::number(minutes)+":0"+QString::number(seconds);
    }
    else
    {
        out = QString::number(minutes)+":"+QString::number(seconds);
    }
    return out;
}

void MainWindow::addSongInTable(Song *song)
{
    int lastRow = ui->musicWidget->rowCount();
    ui->musicWidget->insertRow(lastRow);

    // Artist
    ui->musicWidget->setItem(lastRow, 0, new QTableWidgetItem(song->artist));

    // Title
    ui->musicWidget->setItem(lastRow, 1, new QTableWidgetItem(song->title));

    // Duration
    ui->musicWidget->setItem(lastRow, 2, new QTableWidgetItem(durationToHuman(song->duration)));

    // URL
    ui->musicWidget->setItem(lastRow, 3, new QTableWidgetItem(song->url.toString()));
}

void MainWindow::updateMusicTable()
{
    setPausedUi();
    ui->musicWidget->setRowCount(0);
    ui->musicWidget->clear();
    music->clearHistory();
    QStringList header;
    ui->musicWidget->setColumnCount(4);
    header <<"Artist"<<"Title"<<"Duration"<<"link";
    ui->musicWidget->hideColumn(3);
    ui->musicWidget->setHorizontalHeaderLabels(header);
    ui->musicWidget->verticalHeader()->setVisible(false);

    SongProvider *songProvider = SongProvider::sharedProvider();

    quint16 songsCount = songProvider->songsCount();
    for (quint16 index = 0; index < songsCount; index++)
    {
        Song *song = songProvider->songWithIndex(index);
        this->addSongInTable(song);
    }
    emit ui->musicWidget->cellClicked(0,0);
}

#pragma mark - System Events

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (qvkApp->settings->minToTray)
    {
#ifdef WIN32
        if (trayIcon->isVisible())
        {
            this->hide();
            event->ignore();
        }
#elif defined Q_OS_LINUX
        this->hide();
        event->ignore();
#endif
    }
    else
    {
        event->accept();
    }
}

void MainWindow::trayHandler(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
    {
        setWindowState((windowState() & ~Qt::WindowMinimized) | Qt::WindowActive);
        show();
        activateWindow();
    }
}

#pragma mark - Base

void MainWindow::about()
{
    QString ab = "It is a Player for playing music from Your Vkontakte playlist.\n"
            "More features will be avalible later.\n"
            "\tcurrent version:  '"+QCoreApplication::applicationVersion()+"'\n"
            " credits:\n"
            "\tMe: kazak1377(Maxim Kozachenko)\n"
            "Thanks to:\n"
            "\tQt team\n"
            "\tmembers of c_plus_plus jabber.ru conference";
    QMessageBox::information(this, tr("About QVkPlayer"),ab);
}

MainWindow::~MainWindow()
{
    trayIcon->hide();
    qvkApp->settings->save();
#ifdef Q_OS_LINUX
    system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.qvkplayer.icon /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Quit");
#endif
    delete ui;
    delete trayIcon;
    delete music;
}
