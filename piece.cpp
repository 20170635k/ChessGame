#include "piece.h"

Piece::Piece(){

}
Piece::~Piece(){

}


uint16_t Piece::TYPE_WHITE=1;
uint16_t Piece::TYPE_BLACK=2;

std::vector<std::vector<int>> Piece ::posible(){

    return {{}};
}

void Piece:: setPosition(uint16_t x, uint16_t y){
    Position* p= new Position(x,y);
    position=p;
}
Position* Piece:: getPosition(){
    return position;
}
