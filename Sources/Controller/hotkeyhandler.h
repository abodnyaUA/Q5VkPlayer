#ifndef HOTKEYHANDLER_H
#define HOTKEYHANDLER_H

#include <QObject>

class HotkeyHandler : public QObject
{
    Q_OBJECT



public:
    explicit HotkeyHandler(QObject *parent = 0);

#ifdef Q_OS_WIN32
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
#endif

signals:
    void didTapNextButton();
    void didTapPrevButton();
    void didTapPlayPauseButton();

public slots:

};

#endif // HOTKEYHANDLER_H
