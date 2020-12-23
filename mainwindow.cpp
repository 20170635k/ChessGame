#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

#include "pieceHorse.h"
#include "pieceTower.h"
#include "pieceAlfil.h"
#include "pieceQueen.h"
#include "pieceKing.h"
#include "piecePawn.h"
#include <QScreen>
#include <QTableWidgetItem>
#include "menugame.h"
MainWindow::MainWindow(QApplication &a, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //center window
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    setWindowTitle(QString("Chess Game TO"));
    this->setFixedSize(952,680);
    /*QPalette pal = ui->p11->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    ui->p11->setAutoFillBackground(true);
    ui->p11->setPalette(pal);
    ui->p11->update();*/

    /* QLayoutItem* item=ui->tablero->itemAtPosition(4,4);
    QWidget* widget = item->widget();
    QPushButton* button = dynamic_cast<QPushButton*>(widget);
     button->setIcon(QIcon("C:/Users/pc/Desktop/UNIVERSIDAD/8vo semestre/TO/Proyecto/ChessGame/iconos/tower-b.png"));
*/

    //tanto para las piezas como para el jugados se coloca  1 y 2
    //1: para el blanco
    //2: para el negro


    Piece *piece=nullptr;

    initButtons(0,0,new Tower(piece->TYPE_BLACK));
    initButtons(0,1,new Horse(piece->TYPE_BLACK));
    initButtons(0,2,new Alfil(piece->TYPE_BLACK));
    reyNegro=new King(2);
    initButtons(0,3,reyNegro);
    initButtons(0,4,new Queen(piece->TYPE_BLACK));
    initButtons(0,5,new Alfil(piece->TYPE_BLACK));
    initButtons(0,6,new Horse(piece->TYPE_BLACK));
    initButtons(0,7,new Tower(piece->TYPE_BLACK));

    initButtons(1,0,new Pawn(piece->TYPE_BLACK));
    initButtons(1,1,new Pawn(piece->TYPE_BLACK));
    initButtons(1,2,new Pawn(piece->TYPE_BLACK));
    initButtons(1,3,new Pawn(piece->TYPE_BLACK));
    initButtons(1,4,new Pawn(piece->TYPE_BLACK));
    initButtons(1,5,new Pawn(piece->TYPE_BLACK));
    initButtons(1,6,new Pawn(piece->TYPE_BLACK));
    initButtons(1,7,new Pawn(piece->TYPE_BLACK));

    initButtons(7,0,(new Tower(piece->TYPE_WHITE)));
    initButtons(7,1,(new Horse(piece->TYPE_WHITE)));
    initButtons(7,2,(new Alfil(piece->TYPE_WHITE)));
    reyBlanco=new King(1);
    initButtons(7,3,reyBlanco);
    initButtons(7,4,(new Queen(piece->TYPE_WHITE)));
    initButtons(7,5,(new Alfil(piece->TYPE_WHITE)));
    initButtons(7,6,(new Horse(piece->TYPE_WHITE)));
    initButtons(7,7,(new Tower(piece->TYPE_WHITE)));

    initButtons(6,0,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,1,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,2,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,3,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,4,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,5,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,6,(new Pawn(piece->TYPE_WHITE)));
    initButtons(6,7,(new Pawn(piece->TYPE_WHITE)));


    initButtons(2,0,nullptr);
    initButtons(2,1,nullptr);
    initButtons(2,2,nullptr);
    initButtons(2,3,nullptr);
    initButtons(2,4,nullptr);
    initButtons(2,5,nullptr);
    initButtons(2,6,nullptr);
    initButtons(2,7,nullptr);

    initButtons(3,0,nullptr);
    initButtons(3,1,nullptr);
    initButtons(3,2,nullptr);
    initButtons(3,3,nullptr);
    initButtons(3,4,nullptr);
    initButtons(3,5,nullptr);
    initButtons(3,6,nullptr);
    initButtons(3,7,nullptr);

    initButtons(4,0,nullptr);
    initButtons(4,1,nullptr);
    initButtons(4,2,nullptr);
    initButtons(4,3,nullptr);
    initButtons(4,4,nullptr);
    initButtons(4,5,nullptr);
    initButtons(4,6,nullptr);
    initButtons(4,7,nullptr);

    initButtons(5,0,nullptr);
    initButtons(5,1,nullptr);
    initButtons(5,2,nullptr);
    initButtons(5,3,nullptr);
    initButtons(5,4,nullptr);
    initButtons(5,5,nullptr);
    initButtons(5,6,nullptr);
    initButtons(5,7,nullptr);

    movementManager=new FileUIManagerSave(ui->Log);
    MenuGame * menugame=new MenuGame(this,a,movementManager);
    ui->menu->setIcon(QIcon(":/images/iconos/menuicon.png"));
    QObject::connect(ui->menu,SIGNAL(clicked()),menugame,SLOT(show()));
    /*
    MovementPiece* movement1=new MovementPiece(
                *(reyNegro->getPosition()),
                *(reyBlanco->getPosition()),
                reyNegro,
                movement1->MOVEMENT_CAPTURE
                );
   MovementPiece* movement2=new MovementPiece(
                *(reyNegro->getPosition()),
                *(reyBlanco->getPosition()),
                reyNegro,
                movement1->MOVEMENT_SINGLE
                );

   MovementPiece* movement4=new MovementPiece(
                *(reyBlanco->getPosition()),
                *(reyNegro->getPosition()),
                reyBlanco,
                movement1->MOVEMENT_SHORT_CASTLING
                );
   MovementPiece* movement5=new MovementPiece(
               *(reyNegro->getPosition()),
               *(reyBlanco->getPosition()),
               reyNegro,
               movement1->MOVEMENT_LARGE_CASTLING
               );
   MovementPiece* movement6=new MovementPiece(
               *(reyNegro->getPosition()),
               *(reyBlanco->getPosition()),
               reyNegro,
               movement1->MOVEMENT_LARGE_CASTLING
               );
   MovementPiece* movement7=new MovementPiece(
               *(reyNegro->getPosition()),
               *(reyBlanco->getPosition()),
               reyNegro,
               movement1->MOVEMENT_LARGE_CASTLING
               );


    movement1->plusMovement(movement1->MOVEMENT_JAKE);
    movement2->plusMovement(movement1->MOVEMENT_JAKE_MATE);
    movementManager->addMovement(movement1);
    movementManager->addMovement(movement2);
    movementManager->addMovement(movement4);
    movementManager->addMovement(movement5);
    movementManager->addMovement(movement6);
    movementManager->addMovement(movement7);
*/
    std::cout<<reyBlanco->getPosition()->getPosX()<<std::endl;

    white=new Player(piece->TYPE_WHITE);//inicia al jugador con clave 1 es decir jugador de ficha blanca
    black=new Player(piece->TYPE_BLACK);//inicia al jugador con clave 2 jugador con ficha negra

    QGridLayout* qhb = ui->viewpiecekilledblack;
    QGridLayout* qhw = ui->viewpiecekilledwhite;
    killedViewManager=new ManagerViewPieceKilled(qhw,qhb);

    notificationManager=new NotificationManager();
    notificationManagerSpecial=new NotificationManager();

    ui->Notification->addWidget(notificationManager);
    ui->Notification->addWidget(notificationManagerSpecial);
    //notificationManagerSpecial->showNotification(notificationManagerSpecial->NOTIFICATION_JAKE_MATE_BLACK);
    chronowhite= new Chronometer();
    chronoblack= new Chronometer();
    ui->chronoblack_3->addWidget(chronoblack);
    ui->chronowhite->addWidget(chronowhite);

}

//-----------------------inicia los botones y los coloca en el tablero
void MainWindow::initButtons(int16_t x,int16_t y,Piece* newpiece)
{
    Lockerc *botonnuevo= new Lockerc(this);//Iniciamos el objeto Casillero(Lockerc)
    botonnuevo->setMainWindow(this);//le pasamos un vínculo con la vista principal
    if(newpiece!=nullptr){//si existe una pieza a agregar a este casillero creado entonces la agrega
        std::string ruta=":/images/iconos/"+newpiece->getImagen();
        botonnuevo->setIcon(QIcon(ruta.c_str()));//colocamos el ícono de la pieza
        botonnuevo->setPiece(newpiece);//agregamos el puntero pieza al casillero
        newpiece->setPosition(x,y);
    }
    botonnuevo->setPosition(x,y);

    connect(botonnuevo, SIGNAL (clicked()),botonnuevo, SLOT (handleButton()));/*add event on push*/
    casilleros.push_back(botonnuevo);//agregamos el boton al vector de puntero boton para tener siempre la referencia a estos
    botonnuevo->setMaximumWidth(65);//agregamos las dimensiones del boton
    botonnuevo->setMaximumHeight(65);//
    botonnuevo->setMinimumWidth(65);
    botonnuevo->setMinimumHeight(65);
    botonnuevo->setIconSize(QSize(65,65));//agrega el tamaño al icono de este boton
    ui->tablero->addWidget(botonnuevo,x,y);//agrega el boton al tablero
}

//cambiar el turno de los jugadores
void MainWindow::changeTurn(){
    if(playerturn==white){
        this->playerturn=black;
        chronowhite->pause();
        chronoblack->resume();
        //notificationManager->showNotification(notificationManager->NOTIFICATION_BLACK_TIME);
    }else{
        this->playerturn=white;
        chronoblack->pause();
        chronowhite->resume();
        //notificationManager->showNotification(notificationManager->NOTIFICATION_WHITE_TIME);
    }
}
Player* MainWindow::getPlayerTurn(){return playerturn;}
void MainWindow::setPlayerTurn(Player* turnplayer){playerturn=turnplayer;}
void MainWindow::setPushed(Lockerc * p){pushed=p;}//incresa un puntero del boton precionad
Lockerc* MainWindow::getPushed(){return pushed;}//retorna el puntero al boton precionado
bool MainWindow:: isPushed(){return (pushed!=nullptr)?true:false;}//saber si hay algun boton precionado

//-------------------------------------------------------------------------------------------
//----------------------------Función que controla la dinámica del juego--------------------
//-------------------------------------------------------------------------------------------
void MainWindow::playControl(Lockerc* bpushed)
{
    //si en la tabla ya hay un botón presionado
    //  if(bpushed->getPiece()!=nullptr)
    //    killedViewManager->addPieceKilled(bpushed->getPiece());
    if(this->isPushed()){
        if(bpushed->getPiece()!=nullptr){
            deshabilitarMov();
            if(pushed->getPiece()->getType()==bpushed->getPiece()->getType()){//si es que se ha decidido escoger otra pieza para mover
                //aqui podría haber otra condición para el enrroque
                bpushed->setStroke();//cambia el color de la nueva pieza a resaltado
                pushed->removeStroke();//quita el resaltado de la anterior pieza
                this->setPushed(bpushed);//indica al tablero cual es el nuevo presionado
                habilitarMov(pushed);

            }else{//movimiento de captura
                habilitarMov(pushed);
                if(bpushed->getHabilitado()==true){
                    deshabilitarMov();
                    pushed->getPiece()->firstMove=false;
                    killedViewManager->addPieceKilled(bpushed->getPiece());
                    MovementPiece* movement1=new MovementPiece(
                                *(pushed->getPiece()->getPosition()),
                                *(bpushed->getPiece()->getPosition()),
                                pushed->getPiece(),
                                movement1->MOVEMENT_CAPTURE
                                );
                    bpushed->setPiece(nullptr);
                    //al lugar de movimiento se le agrega la pieza que se quería mover
                    bpushed->setPiece(this->getPushed()->getPiece());
                    //actualizamos la nueva posicion de la pieza
                    bpushed->getPiece()->setPosition(bpushed->getPosition()->getPosX(),bpushed->getPosition()->getPosY());
                    //repinta el casillero(Lockerc) para que se muestre la nueva pieza que lo debe ocupar
                    bpushed->rePaint();
                    //se limpia el puntero del casillero presionada, ya que ya se ejecutó el movimiento y este ya no tiene pieza
                    this->getPushed()->setPiece(nullptr);
                    //se repinta el casillero y como ya se movió no debería haber nada
                    this->pushed->rePaint();
                    pushed->removeStroke();//quita el resaltado de la anterior pieza
                    //al la tabla le indicamos que ya no hay ningun presionado, pues se ejecutó el movimiento
                    this->setPushed(nullptr);
                    jake(bpushed,movement1);
                    movementManager->addMovement(movement1);

                    this->changeTurn();//cambia el turno cuando ya se hizo la jugada
                }
            }
        }else{//movimiento simple
            //aqui irían todo lo necesario para controlar el movimiento

            if(bpushed->getHabilitado()==true){
                deshabilitarMov();
                pushed->getPiece()->firstMove=false;
                //al lugar de movimiento se le agrega la pieza que se quería mover
                bpushed->setPiece(this->getPushed()->getPiece());
                //repinta el casillero(Lockerc) para que se muestre la nueva pieza que lo debe ocupar

                MovementPiece* movement2=new MovementPiece(
                            *(pushed->getPiece()->getPosition()),
                            *(bpushed->getPiece()->getPosition()),
                            pushed->getPiece(),
                            movement2->MOVEMENT_SINGLE
                            );
                this->getPushed()->setPiece(nullptr);
                bpushed->getPiece()->setPosition(bpushed->getPosition()->getPosX(),bpushed->getPosition()->getPosY());
                bpushed->rePaint();
                //se limpia el puntero del casillero presionada, ya que ya se ejecutó el movimiento y este ya no tiene pieza
                //se repinta el casillero y como ya se movió no debería haber nada
                this->pushed->rePaint();
                pushed->removeStroke();//quita el resaltado de la anterior pieza
                //al la tabla le indicamos que ya no hay ningun presionado, pues se ejecutó el movimiento
                this->setPushed(nullptr);
                jake(bpushed,movement2);
                movementManager->addMovement(movement2);
                this->changeTurn();//cambia el turno cuando ya se hizo la jugada
            }else{deshabilitarMov();}
        }
    }
    else{//aqui entra si se presiona el boton que se quiere mover
        if(bpushed->getPiece()!=nullptr){//tiene que tener una pieza, sino que se movería
            if(bpushed->getPiece()->getType()==this->getPlayerTurn()->getColor()){//verifica que la pieza que se quiere mover sea del color del jugador
                this->setPushed(bpushed);//le indico a la tabla que este boton está presionado mas no movido
                pushed->setStroke();//resalta el casillero
                habilitarMov(pushed);
            }
        }
    }
}

void MainWindow::habilitarMov(Lockerc*pushed){
    std::vector<std::vector<int>>a=pushed->getPiece()->posible();
    uint16_t x,y;
    King * rey;
    // int jakeMate=0;
    for(unsigned i=0;i<a.size();++i){
        if(pushed->getPiece()->movLargo()==false){
            if(pushed->getPiece()->getType()==2){
                if(pushed->getPiece()->nombre=="king")
                    rey=new King(2);

                x=pushed->getPosition()->getPosX()+(a[i][0]);
                y=pushed->getPosition()->getPosY()+(a[i][1]);
            }else{
                if(pushed->getPiece()->nombre=="king")
                    rey=new King(1);
                x=pushed->getPosition()->getPosX()-(a[i][0]);
                y=pushed->getPosition()->getPosY()-(a[i][1]);
            }
            if(0<=x&&x<=7&&0<=y&&y<=7){
                QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                QWidget* widget = item->widget();
                Lockerc* button = dynamic_cast<Lockerc*>(widget);

                if(button->getPiece()==nullptr||button->getPiece()->getType()!=pushed->getPiece()->getType()){
                    /*  if(pushed->getPiece()->nombre=="king"){
                        rey->setPosition(x,y);
                        if(!jake(rey)){
                            button->pintarCamino();
                            button->setHabilitado(true);
                        }*/
                    if(pushed->getPiece()->nombre=="pawn"){
                        if(pushed->getPiece()->firstMove==false){
                            if(i==0&&button->getPiece()==nullptr){
                                button->pintarCamino();
                                button->setHabilitado(true);
                            }
                            if((i==1||i==2)&&button->getPiece()!=nullptr){
                                button->pintarCamino();
                                button->setHabilitado(true);
                            }
                        }else{
                            button->pintarCamino();
                            button->setHabilitado(true);
                        }
                    }else{
                        button->pintarCamino();
                        button->setHabilitado(true);
                    }
                }
            }
        }else{
            int ancla=0;
            for(int j=1;j<=7;j++){
                int x=pushed->getPosition()->getPosX()+(a[i][0])*j;
                int y=pushed->getPosition()->getPosY()+(a[i][1])*j;

                if(0<=x&&x<=7&&0<=y&&y<=7){
                    QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                    QWidget* widget = item->widget();
                    Lockerc* button = dynamic_cast<Lockerc*>(widget);
                    if(button->getPiece()!=nullptr&&ancla==1){break;}
                    else{
                        if(button->getPiece()!=nullptr){
                            if(pushed->getPiece()->getType()!=button->getPiece()->getType()){
                                ++ancla;
                                //std::cout<<i<<"  ... "<<j<<"     "<<ancla<<"   "<<x<<"--- "<<y<<std::endl;
                                button->pintarCamino();
                                button->setHabilitado(true);
                                break;
                            }
                            else{break;}
                        }
                        button->pintarCamino();
                        button->setHabilitado(true);
                    }
                }else{break;}
            }
        }
    }
}

void MainWindow::deshabilitarMov(){
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            QLayoutItem* item=ui->tablero->itemAtPosition(i,j);
            QWidget* widget = item->widget();
            Lockerc* button = dynamic_cast<Lockerc*>(widget);
            button->despintarCamino();
            button->setHabilitado(false);
        }
    }
}

void MainWindow:: jake(Lockerc*bpushed,MovementPiece*mov){
    if(bpushed->getPiece()->getType()==2){
        if(searchJake(reyBlanco)){
            std::cout<<"JAKE BLANCOOO "<<std::endl;
            notificationManager->showNotification(notificationManager->NOTIFICATION_JAKE_WHITE);
            mov->plusMovement(mov->MOVEMENT_JAKE);
        }
    }else if(bpushed->getPiece()->getType()==1){
        if(searchJake(reyNegro)){
            std::cout<<"JAKE NEGROOOOO"<<std::endl;
            notificationManager->showNotification(notificationManager->NOTIFICATION_JAKE_BLACK);
            mov->plusMovement(mov->MOVEMENT_JAKE);
        }
    }
}

bool MainWindow:: searchJake(Piece *king){
    uint16_t x,y;
    uint16_t xKing=king->getPosition()->getPosX();
    uint16_t yKing=king->getPosition()->getPosY();
    uint16_t contPawn,contHorse;

    std::vector<std::vector<int>>posibleJake={{1,1},{-1,1},{1,-1},{-1,-1},{-1,0},{1,0},
                                              {0,-1},{0,1},{-1,-2},{1,-2},{-1,2},{1,2},
                                              {2,-1},{2,1},{-2,-1},{-2,1}};

    QLayoutItem* item=ui->tablero->itemAtPosition(xKing,yKing);
    QWidget* widget = item->widget();
    Lockerc* casilleroRey = dynamic_cast<Lockerc*>(widget);
    for(unsigned i=0;i<posibleJake.size();++i){
        contPawn=0;
        contHorse=0;
        for(unsigned j=1;j<=7;++j){
            x=xKing+(posibleJake[i][0])*j;
            y=yKing+(posibleJake[i][1])*j;
            ++contPawn;
            ++contHorse;
            if(0<=x&&x<=7&&0<=y&&y<=7){

                QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                QWidget* widget = item->widget();
                Lockerc* button = dynamic_cast<Lockerc*>(widget);
                if(button->getPiece()!=nullptr){
                    if(button->getPiece()->getType()==king->getType())
                        break;
                    else{
                        if(button->getPiece()->nombre!="pawn"){
                            if((button->getPiece()->nombre=="alfil"||button->getPiece()->nombre=="queen")&&0<=i&&i<=3){
                                std::cout<<"ALFIL DETECTADO "<<std::endl;
                                casilleroRey->pintarJake();
                                return true;
                            }else if((button->getPiece()->nombre=="tower"||button->getPiece()->nombre=="queen")&&4<=i&&i<=7){
                                std::cout<<"TORRE DETECTADO "<<std::endl;
                                casilleroRey->pintarJake();
                                return true;
                            }else if((button->getPiece()->nombre=="horse")&&8<=i&&i<=15&&contHorse==1){
                                std::cout<<"CABALLO DETECTADO "<<std::endl;
                                casilleroRey->pintarJake();
                                return true;
                            }
                        }else if(contPawn==1){
                            if(button->getPiece()->getType()==2&&(0==i||i==1)){
                                std::cout<<"PEON NEGRO DETECTADO "<<std::endl;
                                casilleroRey->pintarJake();
                                return true;
                            }else if(button->getPiece()->getType()==1&&(2==i||i==3)){
                                std::cout<<"PEON BLANCO DETECTADO "<<std::endl;
                                casilleroRey->pintarJake();
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}



