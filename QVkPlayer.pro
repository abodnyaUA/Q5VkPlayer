#-------------------------------------------------
#
# Project created by QtCreator 2013-06-21T21:07:18
#
#-------------------------------------------------

QT       += core gui multimediawidgets dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += webkitwidgets multimedia multimediawidgets

TARGET = QVkPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vkauth.cpp \
    musiccontrol.cpp \
    networker.cpp \
    prefwindow.cpp \
    dbus/dbusadaptor.cpp \
    dbus/dbusmethods.cpp \
    dbus/dbusadaptor1.cpp

HEADERS  += mainwindow.h \
    vkauth.h \
    musiccontrol.h \
    networker.h \
    prefwindow.h \
    dbus/dbusadaptor.h \
    dbus/dbusmethods.h \
    dbus/dbusadaptor1.h

FORMS    += mainwindow.ui \
    prefwindow.ui

QMAKE_LFLAGS += -static-libgcc

RESOURCES += \
    icons.qrc
win32 {
#OS WIN
RC_FILE = winicon.rc
 }
