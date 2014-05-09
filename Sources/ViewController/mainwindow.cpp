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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    music = new MusicControl;
    settingsWindow = new PrefWindow(this);
    settingsWindow->setWindowFlags(Qt::Dialog);
    ui->searchField->setPlaceholderText("Search here");
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
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(trayHandler(QSystemTrayIcon::ActivationReason)));


    ///table setting
    QStringList header;
    ui->musicWidget->setColumnCount(4);
    header <<"Artist"<<"Title"<<"Duration"<<"Download";   //in case of unsuccesseful update....
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
    connect(ui->searchField,SIGNAL(textChanged(QString)),this,SLOT(currentSearch(QString)));
    connect(ui->searchField,SIGNAL(returnPressed()),this,SLOT(updateSearch()));
    connect(ui->musicWidget,SIGNAL(cellClicked(int,int)),this,SLOT(didClickOnCell(int,int)));
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
    connect(NetWorker::sharedNetworker(),SIGNAL(didDownloadSong(Song*)),this,SLOT(updateCellStateOfSong(Song*)));
    ///connection area

    loadSettings();

    this->installEventFilter(qvkApp->hotkeyHandler);
    ui->musicWidget->viewport()->installEventFilter(qvkApp->hotkeyHandler);
    ui->musicWidget->installEventFilter(qvkApp->hotkeyHandler);
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
    this->setWindowTitle(song->fullName());

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
    ui->searchField->setStyleSheet("QLineEdit{background: #FFFFFF;}");    //white for search line
    qDebug()<<text;
    QList<Song *> foundList = SongProvider::sharedProvider()->songsWithTitleContains(text);
    if (!foundList.isEmpty())
    {
        qDebug()<<"Found song: " << foundList[0]->number+1 << foundList[0]->fullName();
        ui->musicWidget->selectRow(foundList[0]->number);
    }
    else
    {
        ui->searchField->setStyleSheet("QLineEdit{background: #FF6666;}");   //error for the searchline
    }
}

void MainWindow::updateSearch()
{
    QList<Song *> foundList = SongProvider::sharedProvider()->songsWithTitleContains(ui->searchField->text());
    if (!foundList.isEmpty())
    {
        int newSongIndex = 0;
        uint current = ui->musicWidget->selectedItems()[0]->row();
        uint founded = foundList[newSongIndex]->number;
        while (newSongIndex < foundList.count() && current >= founded)
        {
            founded = foundList[newSongIndex++]->number;
        }
        if (newSongIndex >= foundList.count())
        {
            newSongIndex = 0;
        }
        qDebug()<<"Found song: " << foundList[newSongIndex]->number+1 << foundList[newSongIndex]->fullName();
        ui->musicWidget->selectRow(foundList[newSongIndex]->number);
    }
}

QString MainWindow::durationToHuman(int seconds)
{
    return QString("%1:%2").arg(seconds / 60).arg(seconds % 60, 2, 10, QChar('0'));;
}

void MainWindow::didClickOnCell(int row, int column)
{
    qDebug() << "didClick On cell" << row << column;
    if (column == 3)
    {
        Song *song = SongProvider::sharedProvider()->songWithIndex(row);
        if (!song->local)
        {
            ui->musicWidget->item(song->number,3)->setText("Downloading...");
            NetWorker::sharedNetworker()->downloadSong(song);
        }
    }
    music->selectSongWithIndex(row);
}

void MainWindow::updateCellStateOfSong(Song *song)
{
    qDebug() << "Update cell with index " << song->number;
    ui->musicWidget->item(song->number,3)->setText("Local copy");
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
    ui->musicWidget->setItem(lastRow, 3, new QTableWidgetItem(song->local ? "Local copy" : "Download"));
}

void MainWindow::updateMusicTable()
{
    setPausedUi();
    ui->musicWidget->setRowCount(0);
    ui->musicWidget->clear();
    music->clearHistory();
    QStringList header;
    ui->musicWidget->setColumnCount(4);
    header <<"Artist"<<"Title"<<"Duration"<<"Download";
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
    QString ab = qvkApp->aboutText();
    QMessageBox::information(this, tr("About QVkPlayer"),ab);
}

MainWindow::~MainWindow()
{
    trayIcon->hide();
    qvkApp->settings->save();
    delete ui;
    delete trayIcon;
    delete music;
}
