#include "piecePawn.h"

Pawn::Pawn(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"pawn-b.png":"pawn-w.png");
}
bool Pawn::move(unsigned char x, uint16_t y){
    return true;
}
bool Pawn::kill() {
    return true;
}
void Pawn::setImagen(std::string imagen) {this->imagen=imagen;}
std::string Pawn::getImagen() {return this->imagen;}
void Pawn::setType(uint16_t type) {this->type=type;}
uint16_t Pawn::getType() {return this->type;}
