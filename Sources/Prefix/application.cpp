#include "application.h"
#include <QFileInfo>

Application::Application(int &argc, char **argv, int) :
    SharedTools::QtSingleApplication(QFileInfo(argv[0]).baseName(),argc, argv)
{
    this->settings = new SettingsController();
    this->hotkeyHandler = new HotkeyHandler();
}

QString Application::aboutText()
{
    return "It is a Player for playing music from Your Vkontakte playlist.\n"
            "More features will be avalible later.\n"
            "\tcurrent version:  '"+this->applicationVersion()+"'\n"
            " credits:\n"
            "\tMe: kazak1377(Maxim Kozachenko)\n"
            "Thanks to:\n"
            "\tQt team\n"
            "\tmembers of c_plus_plus jabber.ru conference";
}
