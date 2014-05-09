#include "notificationssender.h"

#import <Availability.h>
#import <Foundation/Foundation.h>

void NotificationsSender::sendNotification(QString title, QString message)
{
    NSUserNotification *notification = [[NSUserNotification alloc] init];
    notification.title = @"QVkPlayer";
    notification.subtitle = [NSString stringWithUTF8String:title.toStdString().c_str()];
    notification.informativeText = [NSString stringWithUTF8String:message.toStdString().c_str()];
    notification.deliveryDate = [NSDate dateWithTimeIntervalSinceNow:1];

    NSUserNotificationCenter *notificationCenter = [NSUserNotificationCenter defaultUserNotificationCenter];
    [notificationCenter scheduleNotification:notification];
}
