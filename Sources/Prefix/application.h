#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include "Sources/Controller/Settings/settingscontroller.h"

#define qvkApp (static_cast<Application *>(QCoreApplication::instance()))

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv, int = ApplicationFlags);
    SettingsController *settings;
signals:

public slots:

};

#endif // APPLICATION_H
