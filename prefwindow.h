#ifndef PREFWINDOW_H
#define PREFWINDOW_H

#include <QWidget>

namespace Ui
{
class prefWindow;
}

class prefWindow : public QWidget
{
    Q_OBJECT

public:
    explicit prefWindow(QWidget *parent = 0);
    ~prefWindow();

private:
    Ui::prefWindow *ui;
};

#endif // PREFWINDOW_H
