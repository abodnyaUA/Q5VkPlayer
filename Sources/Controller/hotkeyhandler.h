#ifndef HOTKEYHANDLER_H
#define HOTKEYHANDLER_H

#include <QObject>

class HotkeyHandler : public QObject
{
    Q_OBJECT
    ~HotkeyHandler();

#ifdef Q_OS_WIN32
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
#endif

#ifdef Q_OS_LINUX
    void setupDBus();
#endif

public:
    explicit HotkeyHandler(QObject *parent = 0);

signals:
    void didTapNextButton();
    void didTapPrevButton();
    void didTapPlayPauseButton();
};

#endif // HOTKEYHANDLER_H
