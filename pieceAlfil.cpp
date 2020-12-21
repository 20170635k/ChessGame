#include "pieceAlfil.h"
#include <iostream>
Alfil::Alfil(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"alfil-b.png":"alfil-w.png");
    this->nombre="alfil";
}
bool Alfil::move(unsigned char x, uint16_t y){
    return true;
}
bool Alfil::kill() {
    return true;
}
void Alfil::setImagen(std::string imagen) {this->imagen=imagen;}
std::string Alfil::getImagen() {return this->imagen;}
void Alfil::setType(uint16_t type) {this->type=type;}
uint16_t Alfil::getType() {return this->type;}
bool Alfil:: movLargo(){return true;};
std::vector<std::vector<int>> Alfil ::posible(){
    std::vector<std::vector<int>> vec={{1,1},{-1,1},{1,-1},{-1,-1}};
    return vec;
}


