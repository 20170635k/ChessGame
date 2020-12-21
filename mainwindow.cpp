#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include "pieceHorse.h"
#include "pieceTower.h"
#include "pieceAlfil.h"
#include "pieceQueen.h"
#include "pieceKing.h"
#include "piecePawn.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    initButtons(0,0,new Tower(2));
    initButtons(0,1,new Horse(2));
    initButtons(0,2,new Alfil(2));
    reyNegro=new King(2);
    initButtons(0,3,reyNegro);
    initButtons(0,4,new Queen(2));
    initButtons(0,5,new Alfil(2));
    initButtons(0,6,new Horse(2));
    initButtons(0,7,new Tower(2));

    initButtons(1,0,new Pawn(2));
    initButtons(1,1,new Pawn(2));
    initButtons(1,2,new Pawn(2));
    initButtons(1,3,new Pawn(2));
    initButtons(1,4,new Pawn(2));
    initButtons(1,5,new Pawn(2));
    initButtons(1,6,new Pawn(2));
    initButtons(1,7,new Pawn(2));

    initButtons(7,0,(new Tower(1)));
    initButtons(7,1,(new Horse(1)));
    initButtons(7,2,(new Alfil(1)));
    reyBlanco=new King(1);
    initButtons(7,3,reyBlanco);
    initButtons(7,4,(new Queen(1)));
    initButtons(7,5,(new Alfil(1)));
    initButtons(7,6,(new Horse(1)));
    initButtons(7,7,(new Tower(1)));

    initButtons(6,0,(new Pawn(1)));
    initButtons(6,1,(new Pawn(1)));
    initButtons(6,2,(new Pawn(1)));
    initButtons(6,3,(new Pawn(1)));
    initButtons(6,4,(new Pawn(1)));
    initButtons(6,5,(new Pawn(1)));
    initButtons(6,6,(new Pawn(1)));
    initButtons(6,7,(new Pawn(1)));

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
    std::cout<<"prueba :'v";

    std::cout<<reyBlanco->getPosition()->getPosX()<<std::endl;

    white=new Player(1);//inicia al jugador con clave 1 es decir jugador de ficha blanca
    black=new Player(2);//inicia al jugador con clave 2 jugador con ficha negra
    this->setPlayerTurn(white);

    //form save game UI
    formSaveGame= new FileUIManagerSave;
    QObject::connect(ui->saveGamebutton,SIGNAL(clicked()),formSaveGame,SLOT(show()));

    QGridLayout* qhb = ui->viewpiecekilledblack;
    QGridLayout* qhw = ui->viewpiecekilledwhite;
    killedViewManager=new ManagerViewPieceKilled(qhw,qhb);

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

    }else{
        this->playerturn=white;
        chronoblack->pause();
        chronowhite->resume();
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
    //killedViewManager->addPieceKilled(bpushed->getPiece());

    if(this->isPushed()){
        if(bpushed->getPiece()!=nullptr){
            deshabilitarMov(pushed);
            if(pushed->getPiece()->getType()==bpushed->getPiece()->getType()){//si es que se ha decidido escoger otra pieza para mover
                //aqui podría haber otra condición para el enrroque
                bpushed->setStroke();//cambia el color de la nueva pieza a resaltado
                pushed->removeStroke();//quita el resaltado de la anterior pieza
                this->setPushed(bpushed);//indica al tablero cual es el nuevo presionado
                habilitarMov(pushed);
            }else{//aqui el control en caso de que quiera matar a alguien
                //verificar lo necesario
                //si es que está en jaque
                //si es que cumple con el tipo de movimiento de la pieza
                //si coronó como reina
                //etc...
                habilitarMov(pushed);

                if(bpushed->getHabilitado()==true){
                    //std::cout<<"ELIMINAR"<<std::endl;
                    deshabilitarMov(pushed);
                    bpushed->setPiece(nullptr);
                    //al lugar de movimiento se le agrega la pieza que se quería mover
                    bpushed->setPiece(this->getPushed()->getPiece());

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


                    std::cout<<"REYY BLANCOOOO"<<reyBlanco->getPosition()->getPosX()<<std::endl;
                    std::cout<<"REYY NEGROOOOO"<<reyNegro->getPosition()->getPosX()<<std::endl;

                    this->changeTurn();//cambia el turno cuando ya se hizo la jugada
                }

            }
        }else{//en caso contrario
            //aqui irían todo lo necesario para controlar el movimiento
            //si es que está en jaque
            //si es que cumple con el tipo de movimiento de la pieza
            //si coronó como reina
            //etc...

            //por el momento solo estoy colocando el movimiento
            //como si no hubiese reglas pero aqui tú las debes establecer
            //para controlar el movimiento, agrega los métodos que creas conveniente

            if(bpushed->getHabilitado()==true){

                deshabilitarMov(pushed);
                pushed->getPiece()->firstMove=false;
                //al lugar de movimiento se le agrega la pieza que se quería mover
                bpushed->setPiece(this->getPushed()->getPiece());
                //repinta el casillero(Lockerc) para que se muestre la nueva pieza que lo debe ocupar

                bpushed->getPiece()->setPosition(bpushed->getPosition()->getPosX(),bpushed->getPosition()->getPosY());
                bpushed->rePaint();

                //se limpia el puntero del casillero presionada, ya que ya se ejecutó el movimiento y este ya no tiene pieza

                this->getPushed()->setPiece(nullptr);
                //se repinta el casillero y como ya se movió no debería haber nada
                this->pushed->rePaint();
                pushed->removeStroke();//quita el resaltado de la anterior pieza

                //al la tabla le indicamos que ya no hay ningun presionado, pues se ejecutó el movimiento
                this->setPushed(nullptr);

                if(bpushed->getPiece()->getType()==2){
                    if(jake(reyBlanco)){
                        std::cout<<"JAKE BLANCOOO "<<std::endl;
                    }
                }else{
                    if(jake(reyNegro)){
                        std::cout<<"JAKE NEGROOOOO"<<std::endl;
                    }
                }

                //std::cout<<"REYY BLANCOOOO"<<reyBlanco->getPosition()->getPosX()<<std::endl;
                //std::cout<<"REYY NEGROOOOO"<<reyNegro->getPosition()->getPosX()<<std::endl;


                this->changeTurn();//cambia el turno cuando ya se hizo la jugada
            }else{deshabilitarMov(pushed);}

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
    int x,y;
    for(unsigned i=0;i<a.size();++i){
        //std::cout<<pushed->getPiece()->getImagen().c_str()<<std::endl;
        if(pushed->getPiece()->movLargo()==false){
            if(pushed->getPiece()->getType()==2){

                x=pushed->getPosition()->getPosX()+(a[i][0]);
                y=pushed->getPosition()->getPosY()+(a[i][1]);
            }else{
                x=pushed->getPosition()->getPosX()-(a[i][0]);
                y=pushed->getPosition()->getPosY()-(a[i][1]);
            }

            if(0<=x&&x<=7&&0<=y&&y<=7){
                QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                QWidget* widget = item->widget();
                Lockerc* button = dynamic_cast<Lockerc*>(widget);
                if(button->getPiece()==nullptr){
                    button->pintarCamino();
                    button->setHabilitado(true);
                }else{
                    if(button->getPiece()->getType()!=pushed->getPiece()->getType()){
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

void MainWindow::deshabilitarMov(Lockerc*pushed){
    std::vector<std::vector<int>>a=pushed->getPiece()->posible();
    int x,y;
    for(unsigned i=0;i<a.size();++i){
        if(pushed->getPiece()->movLargo()==false){
            if(pushed->getPiece()->getType()==2){
                x=pushed->getPosition()->getPosX()+(a[i][0]);
                y=pushed->getPosition()->getPosY()+(a[i][1]);
            }else{
                x=pushed->getPosition()->getPosX()-(a[i][0]);
                y=pushed->getPosition()->getPosY()-(a[i][1]);
            }

            if(0<=x&&x<=7&&0<=y&&y<=7){
                QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                QWidget* widget = item->widget();
                Lockerc* button = dynamic_cast<Lockerc*>(widget);
                if(button->getPiece()==nullptr){
                    button->despintarCamino();
                    button->setHabilitado(false);
                }else{
                    if(button->getPiece()->getType()!=pushed->getPiece()->getType()){
                        button->despintarCamino();
                        button->setHabilitado(false);
                    }
                }
            }
        }else{
            int ancla=0;
            for(int j=1;j<=7;j++){
                int x=pushed->getPosition()->getPosX()+(a[i][0])*j;
                int y=pushed->getPosition()->getPosY()+(a[i][1])*j;
                //std::cout<<x<<"     "<<y<<std::endl;
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
                                button->despintarCamino();
                                button->setHabilitado(false);
                                break;
                            }
                            else{break;}
                        }

                        button->despintarCamino();
                        button->setHabilitado(false);
                    }
                }else{break;}
            }
        }
    }
}

bool MainWindow:: jake(Piece *king){
    int x,y;
    std::vector<std::vector<int>>a=king->posible();
    for(unsigned i=0;i<a.size();++i){
        for(unsigned j=1;j<=7;++j){
            x=king->getPosition()->getPosX()+(a[i][0])*j;
            y=king->getPosition()->getPosY()+(a[i][1])*j;
            if(0<=x&&x<=7&&0<=y&&y<=7){
                QLayoutItem* item=ui->tablero->itemAtPosition(x,y);
                QWidget* widget = item->widget();
                Lockerc* button = dynamic_cast<Lockerc*>(widget);
                if(button->getPiece()!=nullptr){
                    if(button->getPiece()->getType()==king->getType())
                        break;
                    else{
                        return true;
                    }
                }
            }else{break;}
        }
    }
    return false;
}



MainWindow::~MainWindow()
{
    delete ui;
}



