#include "dbusmethods.h"
#include <QtDebug>

DBusMethods::DBusMethods(QObject *parent) : QObject(parent)
{
    this->canControl();
    this->canGoNext();
    this->canPlay();
    this->canPause();
    this->canGoPrevious();
}

bool DBusMethods::canGoNext() const { return true; }

bool DBusMethods::canPlay() const { return true; }

bool DBusMethods::canGoPrevious() const { return true; }

bool DBusMethods::canPause() const { return true; }

bool DBusMethods::canControl() const { return true; }


void DBusMethods::Next()
{
    emit dbusNext();
}

void DBusMethods::Play()
{
    emit dbusPlayPause();
}

void DBusMethods::PlayPause()
{
    emit dbusPlayPause();
}

void DBusMethods::Previous()
{
    emit dbusPrev();
}

void DBusMethods::Quit()
{
    emit dbusQuit();
}

void DBusMethods::Raise()
{
    emit dbusRaise();
}
