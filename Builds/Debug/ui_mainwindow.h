/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QPushButton *tooglePlayingButton;
    QPushButton *nextButton;
    QSlider *seekSlider;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *searchField;
    QPushButton *toolButton;
    QTableWidget *musicWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *shuffButton;
    QPushButton *repeatButton;
    QSpacerItem *horizontalSpacer;
    QSlider *volumeSlider;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(711, 343);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setMinimumSize(QSize(32, 32));
        prevButton->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/Images/dark/gtk-media-next-rtl.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon);
        prevButton->setIconSize(QSize(20, 20));
        prevButton->setFlat(true);

        horizontalLayout->addWidget(prevButton);

        tooglePlayingButton = new QPushButton(centralWidget);
        tooglePlayingButton->setObjectName(QStringLiteral("tooglePlayingButton"));
        tooglePlayingButton->setMinimumSize(QSize(32, 32));
        tooglePlayingButton->setMaximumSize(QSize(32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/Images/dark/gtk-media-play-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        tooglePlayingButton->setIcon(icon1);
        tooglePlayingButton->setIconSize(QSize(40, 40));
        tooglePlayingButton->setFlat(true);

        horizontalLayout->addWidget(tooglePlayingButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMinimumSize(QSize(32, 32));
        nextButton->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/Images/dark/gtk-media-next-ltr.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon2);
        nextButton->setIconSize(QSize(20, 20));
        nextButton->setFlat(true);

        horizontalLayout->addWidget(nextButton);

        seekSlider = new QSlider(centralWidget);
        seekSlider->setObjectName(QStringLiteral("seekSlider"));
        seekSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(seekSlider);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        searchField = new QLineEdit(centralWidget);
        searchField->setObjectName(QStringLiteral("searchField"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchField->sizePolicy().hasHeightForWidth());
        searchField->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(searchField);

        toolButton = new QPushButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(32, 32));
        toolButton->setMaximumSize(QSize(32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/Images/dark/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon3);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setFlat(true);

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        musicWidget = new QTableWidget(centralWidget);
        musicWidget->setObjectName(QStringLiteral("musicWidget"));

        verticalLayout->addWidget(musicWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        shuffButton = new QPushButton(centralWidget);
        shuffButton->setObjectName(QStringLiteral("shuffButton"));
        shuffButton->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/Images/dark/shuffle.png"), QSize(), QIcon::Normal, QIcon::Off);
        shuffButton->setIcon(icon4);
        shuffButton->setIconSize(QSize(32, 32));
        shuffButton->setCheckable(true);
        shuffButton->setFlat(true);

        horizontalLayout_2->addWidget(shuffButton);

        repeatButton = new QPushButton(centralWidget);
        repeatButton->setObjectName(QStringLiteral("repeatButton"));
        repeatButton->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Resources/Images/dark/repeat.png"), QSize(), QIcon::Normal, QIcon::Off);
        repeatButton->setIcon(icon5);
        repeatButton->setIconSize(QSize(32, 32));
        repeatButton->setCheckable(true);
        repeatButton->setFlat(true);

        horizontalLayout_2->addWidget(repeatButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximum(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(volumeSlider);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 711, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QVkPlayer", 0));
        prevButton->setText(QString());
        tooglePlayingButton->setText(QString());
        nextButton->setText(QString());
        toolButton->setText(QString());
        shuffButton->setText(QString());
        repeatButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
