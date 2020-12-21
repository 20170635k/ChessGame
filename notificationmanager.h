#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H
#include <QWidget>
#include <QLabel>
#include <QTime>
#include <QTimer>
#include <iostream>
#include <QHBoxLayout>
#include <vector>
#include "notification.h"
class NotificationManager:public QWidget
{
private:

    Q_OBJECT
    std::vector<Notification> notifications;
    QTime startTime;
    QTimer t;
    QLabel * l;

    void showStartGame();
    void showJakeWhite();
    void showJakeBlack();
    void showJakeMateWhite();
    void showJakeMateBlack();
    void showWhiteTime();
    void showBlackTime();
    void showGameOver();
    void showWhiteWin();
    void showBlackWin();
public:
    NotificationManager(QWidget *parent=nullptr);
    void showNotification(uint16_t type);

    static uint16_t NOTIFICATION_JAKE_WHITE;
    static uint16_t NOTIFICATION_JAKE_BLACK;
    static uint16_t NOTIFICATION_START_GAME;
    static uint16_t NOTIFICATION_JAKE_MATE_WHITE;
    static uint16_t NOTIFICATION_JAKE_MATE_BLACK;
    static uint16_t NOTIFICATION_WHITE_TIME;
    static uint16_t NOTIFICATION_BLACK_TIME;
    static uint16_t NOTIFICATION_GAME_OVER;
    static uint16_t NOTIFICATION_WHITE_WIN;
    static uint16_t NOTIFICATION_BLACK_WIN;

public slots:
    void updateTime() {
        if(notifications.size()>0){
            if(startTime.elapsed()>=notifications[notifications.size()-1].getDuration()*1000){
                notifications.pop_back();
                stop();
                if(notifications.size()>0){
                    l->setText(notifications[notifications.size()-1].getMessage().c_str());
                            start();
                }

            }
        }
    }
    void start(){ 
        if(notifications.size()>0)
            l->setText(notifications[notifications.size()-1].getMessage().c_str());
        startTime.restart();
        t.start(1000);
        l->show();
    }
    void stop() {
        t.stop();
        l->hide();
    }

};

#endif // NOTIFICATIONMANAGER_H
