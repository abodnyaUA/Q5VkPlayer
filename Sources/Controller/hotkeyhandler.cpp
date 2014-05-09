#include "hotkeyhandler.h"

#ifdef WIN32
#include <windows.h>
#include <qt_windows.h>
#endif

#ifdef Q_OS_LINUX
#include "dbus/dbusmethods.h"
#include "dbus/dbusadaptor.h"
#include "dbus/dbusadaptor1.h"
#include <QtDBus/QDBusConnection>
#endif

HotkeyHandler::HotkeyHandler(QObject *parent) :
    QObject(parent)
{
#ifdef Q_OS_LINUX
    setupDBus();
#endif
}

#ifdef WIN32
bool HotkeyHandler::nativeEvent(const QByteArray &eventType, void *message, long *result)  //GLOBAL HOTKEYS handler
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if (msg->wParam == 66613)        //our defined wParam id for media key next track
    {
        emit didTapNextButton();
    }
    else if (msg->wParam == 66612)  //our defined wParam id for media key prev track
    {
        emit didTapPrevButton();
    }
    else if ((msg->wParam == 69 && useMediaHotkeys)|| msg->wParam == 66611)   //69 is wParam of media key play/pause
    {
        emit didTapPlayPauseButton();
    }

    return false;
}
#endif

#ifdef Q_OS_LINUX
void HotkeyHandler::setupDBus()
{
    DBusMethods* demo = new DBusMethods();
    new DBusAdaptor(demo);
    new DBusAdaptor1(demo);

    QDBusConnection connection = QDBusConnection::sessionBus();
    bool ret = connection.registerService("org.mpris.MediaPlayer2.qvkplayer.mainwindow");
    ret = connection.registerObject("/org/mpris/MediaPlayer2", demo);
    connect(demo,SIGNAL(dbusNext()),this,SIGNAL(didTapNextButton()));
    connect(demo,SIGNAL(dbusPlayPause()),this,SIGNAL(didTapPlayPauseButton());
    connect(demo,SIGNAL(dbusPrev()),this,SIGNAL(didTapPrevButton());
    connect(demo,SIGNAL(dbusQuit()),qApp,SLOT(quit()));
//    connect(demo,SIGNAL(dbusRaise()),this,SLOT(show()));
}
#endif


HotkeyHandler::~HotkeyHandler()
{
#ifdef Q_OS_LINUX
    system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.qvkplayer.icon /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Quit");
#endif
}
