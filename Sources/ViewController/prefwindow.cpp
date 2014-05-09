#include "prefwindow.h"
#include "ui_prefwindow.h"
#include "QDebug"

PrefWindow::PrefWindow(QWidget *parent) : QWidget(parent), ui(new Ui::PrefWindow)
{
    ui->setupUi(this);
    ui->groupBox->hide();
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(sendNewSettings()));
}

PrefWindow::~PrefWindow()
{
    delete ui;
}

void PrefWindow::setUseHotkeysUi(bool use, bool media)
{
    ui->hotkeysCheckBox->setChecked(use);
    ui->comboBox->setCurrentIndex(media ? 0 : 1);
}

void PrefWindow::setUseCacheUi(bool use, QString path)
{
    ui->cacheCheckBox->setChecked(use);
    ui->cachePathLine->setText(path);
}

void PrefWindow::setUseMinTray(bool useTray)
{
    ui->toTrayCheckBox->setChecked(useTray);
}

void PrefWindow::sendNewSettings()
{
    emit setNewSettings(ui->hotkeysCheckBox->isChecked(),
                        ui->comboBox->currentIndex() == 0,
                        ui->cacheCheckBox->isChecked(),
//                        ui->cachePathLine->text(),
                        ui->toTrayCheckBox->isChecked());
    this->hide();
}
