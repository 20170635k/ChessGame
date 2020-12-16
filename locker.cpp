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
    contenedor->playControl(this);}//cuanodo se preciona el boton(casillero) se llama al controlador del juego
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
    pal.setColor(QPalette::Button, QColor(Qt::white));
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
}
Position* Lockerc:: getPosition(){
    return pos;
}




