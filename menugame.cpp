#include "menugame.h"
#include "mainwindow.h"
MenuGame::MenuGame(QApplication &a,QWidget *parent):
    QDialog(parent)
{

    setWindowTitle(QString("Menu Chess"));

    startGame=new QPushButton("Nuevo Juego");
    saveLogGame= new QPushButton("Guardar último Juego");
    exit= new QPushButton("Salir");

    QPixmap fondo(":/images/iconos/chess-menu-fondo.png");
    QPixmap logo(":/images/iconos/logo.png");



    setMaximumHeight(500);
    setMaximumWidth(300);
    setMinimumHeight(500);
    setMinimumWidth(300);

    startGame->setMaximumHeight(40);
    startGame->setMinimumHeight(40);
    saveLogGame->setMaximumHeight(40);
    saveLogGame->setMinimumHeight(40);
    exit->setMaximumHeight(40);
    exit->setMinimumHeight(40);

    imageFondo = new QLabel();
    imageFondo->setPixmap(fondo.scaled(250,170));
    imageLogo = new QLabel();
    imageLogo->setPixmap(logo);

    imageLogo->setAlignment(Qt::AlignCenter);
    layoutContainer= new QVBoxLayout();
    layoutContainer->addWidget(imageLogo);
    layoutContainer->addWidget(startGame);
    layoutContainer->addWidget(saveLogGame);
    layoutContainer->addWidget(exit);
    layoutContainer->addWidget(imageFondo);
    layoutContainer->setAlignment(Qt::AlignCenter);
    setLayout(layoutContainer);


    //form save game UI
    formSaveGame= new FileUIManagerSave;

    QObject::connect(saveLogGame,SIGNAL(clicked()),formSaveGame,SLOT(show()));

    MainWindow *w= new MainWindow();
    QObject::connect(startGame,SIGNAL(clicked()),this,SLOT(hide()));
    QObject::connect(startGame,SIGNAL(clicked()),w,SLOT(show()));

    QObject::connect(exit, SIGNAL(clicked()), &a, SLOT(closeAllWindows()));





}
