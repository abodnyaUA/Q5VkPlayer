#ifndef NOTIFICATIONSSENDER_H
#define NOTIFICATIONSSENDER_H

#include <QString>

class NotificationsSender
{
public:
    void static sendNotification(QString title, QString message);
};

#endif // NOTIFICATIONSSENDER_H
