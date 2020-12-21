#include "notificationmanager.h"

NotificationManager::NotificationManager(QWidget *parent)
    :QWidget(parent)
{
    QHBoxLayout * ly = new QHBoxLayout;
    setLayout(ly);//layout a his widget
    ly->addWidget(l = new QLabel(this));
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    l->setFont(QFont("Agency FB",24));
    l->setMaximumHeight(40);
    l->setMinimumHeight(40);

}
void NotificationManager:: showNotification(uint16_t type){
    notifications.clear();
    if(type==NOTIFICATION_START_GAME){
        showStartGame();
    }else if(type==NOTIFICATION_JAKE_BLACK){
        showJakeBlack();
    }else if(type==NOTIFICATION_JAKE_MATE_BLACK){
        showJakeMateBlack();
    }else if(type==NOTIFICATION_JAKE_WHITE){
        showJakeWhite();
    }else if(type==NOTIFICATION_JAKE_MATE_WHITE){
        showJakeMateWhite();
    }else if(type==NOTIFICATION_WHITE_TIME){
        showWhiteTime();
    }else if(type==NOTIFICATION_BLACK_TIME){
        showBlackTime();
    }else if(type==NOTIFICATION_GAME_OVER){
        showGameOver();
    }else if(type==NOTIFICATION_WHITE_WIN){
        showWhiteWin();
    }else if(type==NOTIFICATION_BLACK_WIN){
        showBlackWin();
    }
    start();
}

void NotificationManager:: showStartGame(){
    notifications.push_back({"Inicia Blanco",2,QColor(192,68,0)});
    notifications.push_back({"En 1",1,QColor(192,68,0)});
    notifications.push_back({"En 2",1,QColor(192,68,0)});
    notifications.push_back({"En 3",1,QColor(192,68,0)});
    notifications.push_back({"Iniciando Juego",2,QColor(192,68,0)});
}
void NotificationManager:: showJakeWhite(){
    notifications.push_back({"Blanco en jaque",5,QColor(192,68,0)});
}
void NotificationManager:: showJakeMateWhite(){
    showGameOver();
    showBlackWin();
    notifications.push_back({"Blanco Jaque mate",2,QColor(192,68,0)});
}
void NotificationManager:: showJakeBlack(){
    notifications.push_back({"Negro en jaque",5,QColor(192,68,0)});

}
void NotificationManager:: showJakeMateBlack(){
    showGameOver();
    notifications.push_back({"Blanco Jaque mate",2,QColor(192,68,0)});
    showWhiteWin();
}
void NotificationManager:: showWhiteTime(){
    notifications.push_back({"Turno de Blanco",2,QColor(192,68,0)});
}
void NotificationManager:: showBlackTime(){
    notifications.push_back({"Turno de Negro",5,QColor(192,68,0)});
}
void NotificationManager:: showGameOver(){
    notifications.push_back({"Fin del Juego",1,QColor(192,68,0)});
}
void NotificationManager:: showWhiteWin(){
    notifications.push_back({"Gana Blanco",3,QColor(192,68,0)});
}
void NotificationManager:: showBlackWin(){
    notifications.push_back({"Gana Negro",3,QColor(192,68,0)});
}

uint16_t NotificationManager:: NOTIFICATION_JAKE_BLACK=1;
uint16_t NotificationManager:: NOTIFICATION_JAKE_WHITE=2;
uint16_t NotificationManager::NOTIFICATION_START_GAME=3;
uint16_t NotificationManager::NOTIFICATION_JAKE_MATE_WHITE=4;
uint16_t NotificationManager::NOTIFICATION_JAKE_MATE_BLACK=5;
uint16_t NotificationManager::NOTIFICATION_WHITE_TIME=6;
uint16_t NotificationManager::NOTIFICATION_BLACK_TIME=7;
uint16_t NotificationManager::NOTIFICATION_GAME_OVER=8;
uint16_t NotificationManager::NOTIFICATION_WHITE_WIN=9;
uint16_t NotificationManager::NOTIFICATION_BLACK_WIN=10;
