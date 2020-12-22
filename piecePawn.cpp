#include "piecePawn.h"

Pawn::Pawn(uint16_t type):
    Piece(PIECE_CODE_PAWN),type{type}
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
bool Pawn:: movLargo(){return false;};
std::vector<std::vector<int>> Pawn ::posible(){

    if(this->firstMove){
        return {{1,0},{2,0}};

    }else
        return {{1,0}};

}
