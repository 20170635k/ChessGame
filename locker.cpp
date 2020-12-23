#include "locker.h"

Lockerc::Lockerc(QWidget *parent):
    QPushButton(parent)
{

}

//métodos para actualizar al puntero Piece que apunta este casillero
void Lockerc::setPiece(Piece* piece)
{
    this->piece=piece;

}
Piece* Lockerc::getPiece(){return this->piece;}

void Lockerc::setMainWindow(MainWindow *mw){contenedor=mw;}

void Lockerc::handleButton(){
    std::cout<<contenedor->enJuego<<std::endl;
    if(contenedor->enJuego){
        contenedor->playControl(this);
    }

}//cuanodo se preciona el boton(casillero) se llama al controlador del juego

void Lockerc::pintarCamino(){
    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, QColor(94,60,0));
    this->setStyleSheet("background-color:blue;");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}
void Lockerc::despintarCamino(){
    QPalette pal = this->palette();
    //pal.setColor(QPalette::Button, QColor(94,60,0));
    this->setStyleSheet("border-color:navy;");
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}

void Lockerc:: setStroke()//le da un borde azul al contorno del boton
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}
void Lockerc:: removeStroke()//le quita el borde azul
{
    QPalette pal = this->palette();
    pal.setColor(QPalette::Button, QColor(94,60,0));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->update();
}
//actualizar la imagen de la ficha en el tablero
void Lockerc::rePaint(){
    if(this->piece!=nullptr){
        std::string ruta=":/images/iconos/"+this->piece->getImagen();
        this->setIcon(QIcon(ruta.c_str()));
    }else{
        this->setIcon(QIcon(""));
    }
}

void Lockerc:: setPosition(uint16_t x, uint16_t y){
    Position* p= new Position(x,y);
    pos=p;
    //piece->getPosition()->getPosX();
}
Position* Lockerc:: getPosition(){
    return pos;
}

bool Lockerc::getHabilitado(){return habilitado;};
void Lockerc::setHabilitado(bool h){this->habilitado=h;};



