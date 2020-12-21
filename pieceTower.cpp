#include "pieceTower.h"

Tower::Tower(uint16_t type):
    type{type}
{
    setImagen((type==this->TYPE_BLACK)?"tower-b.png":"tower-w.png");
}
bool Tower::move(unsigned char x, uint16_t y){
    return true;
}
bool Tower::kill() {
    return true;
}
void Tower::setImagen(std::string imagen) {this->imagen=imagen;}
std::string Tower::getImagen() {return this->imagen;}
void Tower::setType(uint16_t type) {this->type=type;}
uint16_t Tower::getType() {return this->type;}
bool Tower:: movLargo(){return true;};

std::vector<std::vector<int>> Tower ::posible(){

    std::vector<std::vector<int>> vec={{0,1},{0,-1},{1,0},{-1,0}};
    return vec;
}
