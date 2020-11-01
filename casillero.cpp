#include "casillero.h"

/*------------Constructor-----------*/
Casillero:: Casillero(unsigned char x,uint16_t y, Piece* piece):
    piece{piece}
{
    this->position.setPosX(x);
    this->position.setPosY(y);
}

/*-----------Methods Piece----------------*/
Piece* Casillero::getPiece(){
    return this->piece;
}
void Casillero::setPiece(Piece* inpiece){
    this->piece=inpiece;
}
void Casillero::drawPiece(){
//implement
}

/*-----------Methods Position-------------*/
Position Casillero:: getPosition(){
    return this->position;
}
void Casillero:: setPosition(uint16_t pos_y, unsigned char pos_x){
    this->position.setPosY(pos_y);
    this->position.setPosX(pos_x);
}
