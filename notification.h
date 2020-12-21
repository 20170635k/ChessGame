#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <iostream>
#include <QColor>
class Notification
{
private:
    uint16_t duration{0};
    std::string message{""};
    QColor color{Qt::red};
public:
    Notification(std::string message, uint16_t duration,QColor color);
    std::string getMessage();
    uint16_t getDuration();
    QColor getColor();
};

#endif // NOTIFICATION_H
