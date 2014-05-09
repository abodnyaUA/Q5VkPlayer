#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "Sources/Controller/Settings/settingscontroller.h"
#include "Sources/Controller/hotkeyhandler.h"
#include "ThirdParty/QtSingleApplication/qtsingleapplication.h"

#define qvkApp (static_cast<Application *>(QCoreApplication::instance()))

class Application : public SharedTools::QtSingleApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv, int = ApplicationFlags);
    SettingsController *settings;
    HotkeyHandler *hotkeyHandler;

    QString aboutText();
signals:

public slots:

};

#endif // APPLICATION_H
