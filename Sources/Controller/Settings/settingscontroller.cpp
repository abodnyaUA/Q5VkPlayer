#include "settingscontroller.h"
#include "Sources/Controller/Network/networker.h"
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#include <qt_windows.h>
#endif

SettingsController::SettingsController()
{
    settings = new QSettings(this);
    geometry = settings->value("geometry").toByteArray();
    volume = settings->value("volume",50).toInt();
    token = settings->value("token","none").toString();
    userID = settings->value("user_id","none").toString();
    minToTray = settings->value("minToTrayOnClose",false).toBool();
    _useHotkeys = settings->value("useHotkeys",false).toBool();
    _useMediaHotkeys = settings->value("useMediaHotkeys",false).toBool();
    //loadTrayIcon();
}


void SettingsController::setUseHotkeys(bool value)
{
    _useHotkeys = value;
    this->updateHotkeys();
}

void SettingsController::setUseMediaHotkeys(bool value)
{
    _useMediaHotkeys = value;
    this->updateHotkeys();
}

bool SettingsController::useHotkeys()
{
    return _useHotkeys;
}

bool SettingsController::useMediaHotkeys()
{
    return _useMediaHotkeys;
}

void SettingsController::updateHotkeys()
{
#ifdef WIN32
    UnregisterHotKey((HWND)QApplication::activeWindow()->winId(),66613);
    UnregisterHotKey((HWND)QApplication::activeWindow()->winId(),66612);
    UnregisterHotKey((HWND)QApplication::activeWindow()->winId(),66611);
#endif
    if (useHotkeys())
    {
        if (useMediaHotkeys())
        {
#ifdef WIN32
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66613, 0, VK_MEDIA_NEXT_TRACK);
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66612, 0, VK_MEDIA_PREV_TRACK);
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66611, 0, VK_MEDIA_PLAY_PAUSE);
            qDebug()<<"Registered media hotkeys";
#endif
        }
        else
        {
#ifdef WIN32
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66613, MOD_CONTROL, VK_RIGHT);
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66612, MOD_CONTROL, VK_LEFT);
            RegisterHotKey((HWND)QApplication::activeWindow()->winId(),66611, MOD_CONTROL, VK_DOWN);
            qDebug()<<"Registered desktop hotkeys";
#endif
        }
    }
}

void SettingsController::setVolume(int value)
{
    this->volume = value;
}

void SettingsController::save()
{
    settings->setValue("token",NetWorker::sharedNetworker()->getToken());
    settings->setValue("user_id",NetWorker::sharedNetworker()->getUid());
    settings->setValue("volume",volume);
    settings->setValue("geometry",geometry);
    settings->setValue("useHotkeys",_useHotkeys);
    settings->setValue("useMediaHotkeys",_useMediaHotkeys);
    settings->setValue("minToTrayOnClose",minToTray);
    settings->sync();
}
