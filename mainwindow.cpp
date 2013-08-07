#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vkauth.h"
#include "qdebug.h"
#include <QUrlQuery>
#include "musiccontrol.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("Search here");

    ///table setting
    QStringList header;

    ///write table header
    ui->musicWidget->setColumnCount(4);
    header <<"Artist"<<"Title"<<"Duration"<<"link";   //in case of unsuccesseful update....

    ///set table header
    ui->musicWidget->setHorizontalHeaderLabels(header);
    ui->musicWidget->verticalHeader()->setVisible(false);
    ui->musicWidget->setShowGrid(false);

    ///ui->musicWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    ui->musicWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->musicWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->musicWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //connect(ui->toolButton,SIGNAL(clicked()),SLOT(loginSlot()));

    ////////////////////////////////////////////////Creating actions
    QAction *login = new QAction(tr("Login"),this);
    QAction *About = new QAction(tr("About"),this);
    QAction *refrsh = new QAction(tr("Refresh"),this);
    connect(refrsh,SIGNAL(triggered()),this,SLOT(getAudioList()));
    connect(login, SIGNAL(triggered()), this, SLOT(loginSlot()));
    connect(About, SIGNAL(triggered()), this, SLOT(about()));

    ////////////////////////////////////////////////Creating menu
    QMenu *eyemenu = new QMenu("Options", ui->toolButton);
    eyemenu->addAction(refrsh);
    eyemenu->addAction(login);
    eyemenu->addSeparator();
    eyemenu->addAction(About);
    ///////////////////////////////////////////////making menu button
    ui->toolButton->setMenu(eyemenu);

    ///connection area
    /*musicControl **/music = new musicControl;
    connect(this,SIGNAL(setPlayingOrder(QList<QUrl>)),music,SLOT(setPlayList(QList<QUrl>)));
    connect(ui->musicWidget,SIGNAL(cellDoubleClicked(int,int)),music,SLOT(playThatSong(int,int)));
    connect(ui->musicWidget,SIGNAL(cellClicked(int,int)),music,SLOT(setSongIndex(int,int)));
    connect(ui->shuffButton,SIGNAL(toggled(bool)),music,SLOT(shuffleMode(bool)));
    connect(ui->nextButton,SIGNAL(clicked()),music,SLOT(playNextSong()));
    connect(music,SIGNAL(setIndexToUi(int,int)),this,SLOT(setSongUi(int,int)));
    connect(ui->prevButton,SIGNAL(clicked()),music,SLOT(playPrevSong()));
    connect(ui->tooglePlayingButton,SIGNAL(clicked()),music,SLOT(changeState()));
    connect(music,SIGNAL(setPlayingUi()),this,SLOT(setPlayingUi()));
    connect(music,SIGNAL(setPausedUi()),this,SLOT(setPausedUi()));
    ///connection area


    ///auto refresh and autologin
    ///checking file
    QFile file("token");
    if(!file.open(QIODevice::ReadOnly))
    {
        loginSlot();
    }
    else
    {
        QTextStream in(&file);
        token = in.readLine();
        file.close();
        getAudioList();
    }
}

void MainWindow::setShuffle()
{
}

void MainWindow::setPlayingUi()
{
    ui->tooglePlayingButton->setIcon(QIcon(QPixmap(":/icons/dark/gtk-media-pause.png")));
}

void MainWindow::setPausedUi()
{
    ui->tooglePlayingButton->setIcon(QIcon(QPixmap(":/icons/dark/gtk-media-play-ltr.png")));
}

void MainWindow::setSongUi(int current,int /*prev*/)
{
    ui->musicWidget->scrollToItem(ui->musicWidget->item(current,0));
    this->setWindowTitle(ui->musicWidget->item(current,0)->text()+"  -  "+
                         ui->musicWidget->item(current,1)->text());
//    ui->musicWidget->item(current,0)->setFont(QFont(bold));
//    ui->musicWidget->item(current,1)->setFont(bold);
}

void MainWindow::loginSlot()
{
    vkAuth *loginWindow = new vkAuth;
    QObject::connect(loginWindow,SIGNAL(tokenSet(QString,QString)),SLOT(setToken(QString,QString)));
    loginWindow->show();
}

void MainWindow::about()
{
    QMessageBox::information(this, tr("About QVkPlayer"),
                             tr("It is a Player for playing music from Your Vkontakte playlist.\n"
                                "More features will be avalible later.\n"
                                "\tfirst released version  'alpha 0.1'\n"
                                " credits:\n"
                                "\tMe: kazak1377(Maxim Kozachenko)\n"
                                "Thanks to:\n"
                                "\tQt team\n"
                                "\tmembers of c_plus_plus jabber.ru conference"));
}

void MainWindow::setToken(QString value,QString value2)
{
    token = value;
    userId = value2;
    this->getAudioList();
}

QString MainWindow :: durationToHuman(int d)
{
    int minutes = d/60;
    int seconds = d%60;
    QString out;
    if(seconds<10)
    {
        out = QString::number(minutes)+":0"+QString::number(seconds);
    }
    else
        out = QString::number(minutes)+":"+QString::number(seconds);
    return out;
}

void MainWindow::setTableLine(QStringList line)
{
    int lastRow = ui->musicWidget->rowCount();
    ui->musicWidget->insertRow(lastRow);
    for(int i=0;i<=3;i++)
    {
        QTableWidgetItem *item=new QTableWidgetItem (line[i]);
        ui->musicWidget->setItem(lastRow,i,item);
    }
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug()<<"Audio list get";
        QXmlStreamReader xml(reply);
        while(!xml.atEnd() && !xml.hasError())
        {
            /* Read next element.*/
            QXmlStreamReader::TokenType token = xml.readNext();
            /* If token is just StartDocument, we'll go to next.*/
            if(token == QXmlStreamReader::StartDocument)
            {
                continue;
            }
            /* If token is StartElement, we'll see if we can read it.*/
            if(token == QXmlStreamReader::StartElement)
            {
                /* If it's named persons, we'll go to the next.*/
                if(xml.name() == "audio")
                {
                    tableLine.clear();
                    continue;
                }
                /* If it's named person, we'll dig the information from there.*/
                if(xml.name() == "artist")
                {
                    tableLine.append(xml.readElementText());
                }
                if(xml.name() == "title")
                {
                    tableLine.append(xml.readElementText());
                }
                if(xml.name() == "duration")
                {
                    QString duration;
                    duration = durationToHuman(xml.readElementText().toInt());
                    tableLine.append(duration);
                }
                if(xml.name() == "url")
                {
                    QString line = xml.readElementText();
                    tableLine.append(line);
                    linkList.append(QUrl(line));
                    setTableLine(tableLine);
                }

            }
        }
        /* Error handling. */
        if(xml.hasError())
        {
            QMessageBox::critical(this,
                                  "QXSRExample::parseXML",
                                  xml.errorString(),
                                  QMessageBox::Ok);
        }
        /* Removes any device() or data from the reader
            * and resets its internal state to the initial state. */
        xml.clear();
    }
    else
    {
        qDebug()<<reply->errorString();
    }
    emit setPlayingOrder(linkList);
}

void MainWindow::getAudioList()    //it is our request function
{
    linkList.clear();
    QUrl rAudioUrl("https://api.vk.com/method/audio.get.xml?");
    QUrlQuery tmpUrl;
    ui->musicWidget->clear();
    ui->musicWidget->setRowCount(0);
    QStringList header;
    header <<"Artist"<<"Title"<<"Duration"<< "link";
    ui->musicWidget->setHorizontalHeaderLabels(header);
    tmpUrl.addQueryItem("uid", userId);
    tmpUrl.addQueryItem("access_token", token);
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    rAudioUrl.setQuery(tmpUrl);
    manager->get(QNetworkRequest(rAudioUrl));
}

MainWindow::~MainWindow()
{
    delete ui;
}
