#include "movementpiece.h"

MovementPiece::MovementPiece(Position from,Position to,Piece *piece,std::string typeMove)
{
    pieceMoved=piece;

    if(typeMove.compare(MOVEMENT_SINGLE)==0){
      result=piece->getPieceCode();
      result.push_back(to.parseToChar(to.getPosY()));
      result=result+std::to_string(8-to.getPosX());
    }else if(typeMove.compare(MOVEMENT_CAPTURE)==0){
        if(piece->getPieceCode().compare(piece->PIECE_CODE_PAWN))
            result.push_back(from.parseToChar(from.getPosY()));
      result+=MOVEMENT_CAPTURE;
      result.push_back(to.parseToChar(to.getPosY()));
      result=result+std::to_string(8-to.getPosX());
    }else if(typeMove.compare(MOVEMENT_JAKE)==0){
      result=piece->getPieceCode();
      result.push_back(to.parseToChar(to.getPosY()));
      result=result+std::to_string( 8-to.getPosX());
      result+=MOVEMENT_JAKE;
    }else if(typeMove.compare(MOVEMENT_SHORT_CASTLING)==0){
      result=result+MOVEMENT_SHORT_CASTLING;
    }else if(typeMove.compare(MOVEMENT_LARGE_CASTLING)==0){
      result=result+MOVEMENT_LARGE_CASTLING;
    }else if(typeMove.compare(MOVEMENT_JAKE_MATE)==0){
        result=piece->getPieceCode();
        result.push_back(to.parseToChar(to.getPosY()));
        result=result+std::to_string( 8-to.getPosX());
        result+=MOVEMENT_JAKE_MATE;
    }
}
QString MovementPiece::getMovement(){
    return QString(result.c_str());
}
void MovementPiece::plusMovement(std::string type){
 result+=type;
}
Piece* MovementPiece::getPieceMoved(){return pieceMoved;}

std::string MovementPiece::MOVEMENT_SINGLE="";
std::string MovementPiece::MOVEMENT_CAPTURE="x";
std::string MovementPiece::MOVEMENT_JAKE="+";
std::string MovementPiece::MOVEMENT_SHORT_CASTLING="0-0";
std::string MovementPiece::MOVEMENT_LARGE_CASTLING="0-0-0";
std::string MovementPiece::MOVEMENT_JAKE_MATE="#";
std::string MovementPiece::MOVEMENT_NOTHING="nothing";
