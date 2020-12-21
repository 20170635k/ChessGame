#include "notification.h"

Notification::Notification(std::string message, uint16_t duration,QColor color)
    :duration{duration},message{message}, color{color}
{

}

std::string Notification::getMessage(){return message;}
uint16_t Notification::getDuration(){return duration;}
QColor Notification:: getColor(){return color;}
