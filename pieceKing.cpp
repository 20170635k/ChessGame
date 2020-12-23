#include "pieceKing.h"

King::King(uint16_t type):
    Piece(PIECE_CODE_KING),type{type}
{
    setImagen((type==this->TYPE_BLACK)?"king-b.png":"king-w.png");
    this->nombre="king";
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

bool King::movLargo(){return false;};
std::vector<std::vector<int>>King ::posible(){

    std::vector<std::vector<int>> vec={{1,1},{-1,1},{1,-1},{-1,-1},{-1,0},{1,0},{0,-1},{0,1}};
    return vec;
}
