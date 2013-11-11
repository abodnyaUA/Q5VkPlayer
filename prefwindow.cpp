#include "prefwindow.h"
#include "ui_prefwindow.h"

prefWindow::prefWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prefWindow)
{
    ui->setupUi(this);
}

prefWindow::~prefWindow()
{
    delete ui;
}
