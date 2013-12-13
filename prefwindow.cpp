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
    if (media)
        ui->comboBox->setCurrentIndex(0);
    else
        ui->comboBox->setCurrentIndex(1);
}

void PrefWindow::setUseCacheUi(bool use, QString path)
{
    ui->cacheCheckBox->setChecked(use);
    ui->cachePathLine->setText(path);
}

void PrefWindow::sendNewSettings()
{
    if (ui->comboBox->currentIndex() == 0)
        emit setNewSettings(ui->hotkeysCheckBox->isChecked(),
                            true, ui->cacheCheckBox->isChecked(), ui->cachePathLine->text());
    else if (ui->comboBox->currentIndex() == 1)
        emit setNewSettings(ui->hotkeysCheckBox->isChecked(),
                            false, ui->cacheCheckBox->isChecked(), ui->cachePathLine->text());
    this->hide();
}
