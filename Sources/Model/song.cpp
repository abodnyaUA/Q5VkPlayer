#include "song.h"

Song::Song(QObject *parent) : QObject(parent)
{
    local = false;
}

QString Song::fullName()
{
    return this->artist + " - " + this->title;
}
