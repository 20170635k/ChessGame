#include "pieceHorse.h"

Horse::Horse(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"horse-b.png":"horse-w.png");
}
bool Horse::move(unsigned char x, uint16_t y){
    return true;
}
bool Horse::kill() {
    return true;
}
void Horse::setImagen(std::string imagen) {this->imagen=imagen;}
std::string Horse::getImagen() {return this->imagen;}
void Horse::setType(uint16_t type) {this->type=type;}
uint16_t Horse::getType() {return this->type;}