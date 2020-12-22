#include "piece.h"

Piece::Piece(std::string code):
codePiece{code}
{

}
Piece::~Piece(){

}


uint16_t Piece::TYPE_WHITE=1;
uint16_t Piece::TYPE_BLACK=2;
std::string Piece::PIECE_CODE_HORSE="C";
std::string Piece::PIECE_CODE_ALFIL="A";
std::string Piece::PIECE_CODE_KING="R";
std::string Piece::PIECE_CODE_QUEEN="D";
std::string Piece::PIECE_CODE_PAWN="";
std::string Piece::PIECE_CODE_TOWER="T";

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

std::string Piece:: getPieceCode(){
    return this->codePiece;
}
