#include "hotkeyhandler.h"

#ifdef WIN32
#include <windows.h>
#include <qt_windows.h>
#endif

HotkeyHandler::HotkeyHandler(QObject *parent) :
    QObject(parent)
{
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
