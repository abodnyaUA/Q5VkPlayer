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
    Sources/Model/songprovider.cpp \
    Sources/Controller/Settings/settingscontroller.cpp \
    Sources/Prefix/application.cpp \
    Sources/Controller/hotkeyhandler.cpp \
    ThirdParty/QtSingleApplication/qtsingleapplication.cpp \
    ThirdParty/QtSingleApplication/qtlockedfile.cpp \
    ThirdParty/QtSingleApplication/qtlocalpeer.cpp

HEADERS += \
    Sources/ViewController/mainwindow.h \
    Sources/Controller/Network/vkauth.h \
    Sources/Controller/musiccontrol.h \
    Sources/ViewController/prefwindow.h \
    Sources/Model/song.h \
    Sources/Model/songprovider.h \
    Sources/Controller/Settings/settingscontroller.h \
    Sources/Prefix/application.h \
    Sources/Controller/hotkeyhandler.h \
    Sources/Controller/notificationssender.h \
    ThirdParty/QtSingleApplication/qtsingleapplication.h \
    ThirdParty/QtSingleApplication/qtlockedfile.h \
    ThirdParty/QtSingleApplication/qtlocalpeer.h \
    Sources/Controller/Network/networker.h

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

    SOURCES += \
    Sources/Controller/notificationssender.cpp \
    ThirdParty/QtSingleApplication/qtlockedfile_win.cpp
}

# UNIX
unix {
    SOURCES += \
    ThirdParty/QtSingleApplication/qtlockedfile_unix.cpp
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

    SOURCES += \
    Sources/Controller/notificationssender.cpp
}

# MAC OS X
macx {
    LIBS += -framework Foundation
    ICON = Resources/Images/appicon/qvk.icns
    QMAKE_INFO_PLIST = Resources/Plist/QVkPlayer-Info.plist
    OTHER_FILES += Resources/Plist/QVkPlayer-Info.plist
    QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc++
    CONFIG+=c++11

    OBJECTIVE_SOURCES += \
    Sources/Controller/notificationssender.mm
#    Sources/Model/songprovider_mac.mm
}
