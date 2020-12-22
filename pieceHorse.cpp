#include "pieceHorse.h"

Horse::Horse(uint16_t type):
    Piece(PIECE_CODE_HORSE),type{type}
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
bool Horse:: movLargo(){return false;};

std::vector<std::vector<int>> Horse ::posible(){

    std::vector<std::vector<int>> vec={{-1,-2},{1,-2},{-1,2},{1,2},{2,-1},{2,1},{-2,-1},{-2,1}};
    return vec;
}

