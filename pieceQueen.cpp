#include "pieceQueen.h"

Queen::Queen(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"queen-b.png":"queen-w.png");
}
bool Queen::move(unsigned char x, uint16_t y){
    return true;
}
bool Queen::kill() {
    return true;
}
void Queen::setImagen(std::string imagen) {this->imagen=imagen;}
std::string Queen::getImagen() {return this->imagen;}
void Queen::setType(uint16_t type) {this->type=type;}
uint16_t Queen::getType() {return this->type;}
