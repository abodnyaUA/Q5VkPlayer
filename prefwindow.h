#ifndef PREFWINDOW_H
#define PREFWINDOW_H

#include <QWidget>

namespace Ui {
class PrefWindow;
}

class PrefWindow : public QWidget
{
    Q_OBJECT
    bool useHotkeys;
    bool useMediaKeys;
public:
    explicit PrefWindow(QWidget *parent = 0);
    ~PrefWindow();

private:
    Ui::PrefWindow *ui;

public slots:
    void setUseHotkeysUi(bool use, bool media);
    void setUseCacheUi(bool use, QString path);

signals:
    void changedUseCacheSettings(bool use, QString path);
    void changedUseHotkeysSettings(bool use, int index);
    void setNewSettings(bool use, bool media, bool cache, QString path);
private slots:
    void sendNewSettings();

};

#endif // PREFWINDOW_H
