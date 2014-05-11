#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QObject>
#include <QSettings>

class SettingsController : public QObject
{
    Q_OBJECT
    QSettings *settings;

    bool _useHotkeys;
    bool _useMediaHotkeys;

    void updateHotkeys();
public:
    bool useCache;
    bool minToTray;
    bool isUnity;
    bool shuffle;
    QByteArray geometry;
    uint volume;
    QString token;
    QString userID;

    void setUseHotkeys(bool);
    void setUseMediaHotkeys(bool);
    bool useHotkeys();
    bool useMediaHotkeys();

    SettingsController();
    void save();

public slots:
    void setVolume(int);

signals:
    void settingsDidUpdated();
};

#endif // SETTINGSCONTROLLER_H
