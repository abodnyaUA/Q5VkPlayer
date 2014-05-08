/********************************************************************************
** Form generated from reading UI file 'prefwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFWINDOW_H
#define UI_PREFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrefWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cacheCheckBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *cachePathLine;
    QPushButton *cachePathBrowseButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *hotkeysCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *comboBox;
    QCheckBox *toTrayCheckBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QWidget *PrefWindow)
    {
        if (PrefWindow->objectName().isEmpty())
            PrefWindow->setObjectName(QStringLiteral("PrefWindow"));
        PrefWindow->resize(298, 180);
        verticalLayout_3 = new QVBoxLayout(PrefWindow);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(PrefWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cacheCheckBox = new QCheckBox(groupBox);
        cacheCheckBox->setObjectName(QStringLiteral("cacheCheckBox"));

        horizontalLayout_2->addWidget(cacheCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cachePathLine = new QLineEdit(groupBox);
        cachePathLine->setObjectName(QStringLiteral("cachePathLine"));

        horizontalLayout->addWidget(cachePathLine);

        cachePathBrowseButton = new QPushButton(groupBox);
        cachePathBrowseButton->setObjectName(QStringLiteral("cachePathBrowseButton"));

        horizontalLayout->addWidget(cachePathBrowseButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(PrefWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        hotkeysCheckBox = new QCheckBox(groupBox_2);
        hotkeysCheckBox->setObjectName(QStringLiteral("hotkeysCheckBox"));

        horizontalLayout_5->addWidget(hotkeysCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);


        horizontalLayout_4->addWidget(groupBox_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        toTrayCheckBox = new QCheckBox(PrefWindow);
        toTrayCheckBox->setObjectName(QStringLiteral("toTrayCheckBox"));

        verticalLayout_3->addWidget(toTrayCheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(PrefWindow);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        saveButton = new QPushButton(PrefWindow);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(PrefWindow);
        QObject::connect(cancelButton, SIGNAL(clicked()), PrefWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(PrefWindow);
    } // setupUi

    void retranslateUi(QWidget *PrefWindow)
    {
        PrefWindow->setWindowTitle(QApplication::translate("PrefWindow", "QVkPlayer - Settings", 0));
        groupBox->setTitle(QApplication::translate("PrefWindow", "\320\241ache settings", 0));
        cacheCheckBox->setText(QApplication::translate("PrefWindow", "\320\241ache music", 0));
        cachePathBrowseButton->setText(QApplication::translate("PrefWindow", "browse", 0));
        groupBox_2->setTitle(QApplication::translate("PrefWindow", "Hotkeys settings", 0));
        hotkeysCheckBox->setText(QApplication::translate("PrefWindow", "Use hotkeys?", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PrefWindow", "Media keys", 0)
         << QApplication::translate("PrefWindow", "Ctrl+arrows", 0)
        );
        toTrayCheckBox->setText(QApplication::translate("PrefWindow", "Minimize to tray on close", 0));
        cancelButton->setText(QApplication::translate("PrefWindow", "cancel", 0));
        saveButton->setText(QApplication::translate("PrefWindow", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class PrefWindow: public Ui_PrefWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFWINDOW_H
