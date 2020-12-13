#include "pieceKing.h"

King::King(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"king-b.png":"king-w.png");
}
bool King::move(unsigned char x, uint16_t y){
    return true;
}
bool King::kill() {
    return true;
}
void King::setImagen(std::string imagen) {this->imagen=imagen;}
std::string King::getImagen() {return this->imagen;}
void King::setType(uint16_t type) {this->type=type;}
uint16_t King::getType() {return this->type;}
