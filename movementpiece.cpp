#include "movementpiece.h"

MovementPiece::MovementPiece(Position from,Position to,Piece *piece,std::string typeMove,std::string secondType)
{
    pieceMoved=piece;

    if(typeMove.compare(MOVEMENT_SINGLE)==0){
      result=piece->getPieceCode();
      result.push_back(to.parseToChar(to.getPosX()));
      result=result+std::to_string( to.getPosY());
    }else if(typeMove.compare(MOVEMENT_CAPTURE)==0){
      result=piece->getPieceCode();
      result.push_back(from.parseToChar(from.getPosX()));
      result+=MOVEMENT_CAPTURE;
      result.push_back(to.parseToChar(to.getPosX()));
      result=result+std::to_string( to.getPosY());
    }else if(typeMove.compare(MOVEMENT_JAKE)==0){
      result=piece->getPieceCode();
      result.push_back(to.parseToChar(to.getPosX()));
      result=result+std::to_string( to.getPosY());
      result+=MOVEMENT_JAKE;
    }else if(typeMove.compare(MOVEMENT_SHORT_CASTLING)==0){
      result=result+MOVEMENT_SHORT_CASTLING;
    }else if(typeMove.compare(MOVEMENT_LARGE_CASTLING)==0){
      result=result+MOVEMENT_LARGE_CASTLING;
    }else if(typeMove.compare(MOVEMENT_JAKE_MATE)==0){
        result=piece->getPieceCode();
        result.push_back(to.parseToChar(to.getPosX()));
        result=result+std::to_string( to.getPosY());
        result+=MOVEMENT_JAKE_MATE;
    }
    if(secondType.compare(MOVEMENT_NOTHING)!=0){
        std::cout<<"está entrando\n";
        result+=secondType;
    }

}
QString MovementPiece::getMovement(){
    return QString(result.c_str());
}
Piece* MovementPiece::getPieceMoved(){return pieceMoved;}

std::string MovementPiece::MOVEMENT_SINGLE="";
std::string MovementPiece::MOVEMENT_CAPTURE="x";
std::string MovementPiece::MOVEMENT_JAKE="+";
std::string MovementPiece::MOVEMENT_SHORT_CASTLING="0-0";
std::string MovementPiece::MOVEMENT_LARGE_CASTLING="0-0-0";
std::string MovementPiece::MOVEMENT_JAKE_MATE="#";
std::string MovementPiece::MOVEMENT_NOTHING="nothing";
