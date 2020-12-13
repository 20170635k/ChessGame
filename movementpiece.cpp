#include "movementpiece.h"

MovementPiece::MovementPiece()
{

}

void MovementPiece:: setPieceMoved(Piece* piecemoved){
    pieceMoved=piecemoved;
}
Piece* MovementPiece:: getPieceModed(){
    return pieceMoved;
}
void MovementPiece::addItemDescMovement(std::string itemdes){
    movement.push_back(itemdes);
}
QString MovementPiece::formatString(){//falta
    QString retorno{"hola"};
    return retorno;
}
