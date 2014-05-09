#include "application.h"

Application::Application(int &argc, char **argv, int flags) : QApplication(argc, argv,flags)
{
    this->settings = new SettingsController();
    this->hotkeyHandler = new HotkeyHandler();
}
