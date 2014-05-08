#ifndef DBUSMETHODS_H
#define DBUSMETHODS_H

#include <QObject>
#include "dbus/dbusadaptor.h"
#include "dbus/dbusadaptor1.h"

class DBusMethods : public QObject
{
    Q_OBJECT
public:
    explicit DBusMethods(QObject *parent = 0);

public: // PROPERTIES

    Q_PROPERTY(bool CanGoNext READ canGoNext)
    bool canGoNext() const;

    Q_PROPERTY(bool CanControl READ canControl)
    bool canControl() const;

    Q_PROPERTY(bool CanGoPrevious READ canGoPrevious)
    bool canGoPrevious() const;

    Q_PROPERTY(bool CanPause READ canPause)
    bool canPause() const;

    Q_PROPERTY(bool CanPlay READ canPlay)
    bool canPlay() const;

public Q_SLOTS: // METHODS
    void Next();
    void Play();
    void PlayPause();
    void Previous();

    void Quit();
    void Raise();

signals:
    void dbusNext();
    void dbusPrev();
    void dbusPlayPause();
    void dbusRaise();
    void dbusQuit();

};

#endif // DBUSMETHODS_H
