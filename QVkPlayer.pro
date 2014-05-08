#-------------------------------------------------
#
# Project created by QtCreator 2013-06-21T21:07:18
#
#-------------------------------------------------

QT       += core gui multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += webkitwidgets multimedia multimediawidgets

#GENERAL

TARGET = QVkPlayer
TEMPLATE = app

##############################################
# SOURCES
##############################################

SOURCES += \
    Sources/Prefix/main.cpp\
    Sources/ViewController/mainwindow.cpp \
    Sources/Controller/Network/vkauth.cpp \
    Sources/Controller/musiccontrol.cpp \
    Sources/Controller/Network/networker.cpp \
    Sources/ViewController/prefwindow.cpp \
    Sources/Model/song.cpp \
    Sources/Model/songprovider.cpp

HEADERS += \
    Sources/ViewController/mainwindow.h \
    Sources/Controller/Network/vkauth.h \
    Sources/Controller/musiccontrol.h \
    Sources/Controller/Network/networker.h \
    Sources/ViewController/prefwindow.h \
    Sources/Model/song.h \
    Sources/Model/songprovider.h

FORMS += \
    Resources/UI/mainwindow.ui \
    Resources/UI/prefwindow.ui

RESOURCES += \
    Resources/Images/icons.qrc


##############################################
# OS SPECIFIED
##############################################

# WINDOWS
win32 {
    QMAKE_LFLAGS += -static-libgcc
    RC_FILE = Resources/Images/appicon/winicon.rc
}

# LINUX
unix : !macx {
    QT       += dbus
    QMAKE_LFLAGS += -static-libgcc
    SOURCES += \
        ThirdParty/dbus/dbusadaptor.cpp \
        ThirdParty/dbus/dbusmethods.cpp \
        ThirdParty/dbus/dbusadaptor1.cpp
    HEADERS += \
        ThirdParty/dbus/dbusadaptor.h \
        ThirdParty/dbus/dbusmethods.h \
        ThirdParty/dbus/dbusadaptor1.h
}

# MAC OS X
macx {
    ICON = Resources/Images/appicon/qvk.icns
    RC_FILE = Resources/Images/appicon/qvk.icns
    QMAKE_INFO_PLIST = Resources/Plist/QVkPlayer-Info.plist
    OTHER_FILES += Resources/Plist/QVkPlayer-Info.plist
    QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc++
    CONFIG+=c++11
}
