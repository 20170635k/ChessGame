#ifndef MOVEMENTPIECE_H
#define MOVEMENTPIECE_H
#include "position.h"
#include "piece.h"
#include <QTextEdit>
#include <iostream>
class MovementPiece
{
public:
    MovementPiece(Position from,Position to,Piece *pieza,std::string typeMove,std::string secondType=MOVEMENT_NOTHING);
    QString getMovement();
    Piece* getPieceMoved();
    static std::string MOVEMENT_SINGLE;
    static std::string MOVEMENT_CAPTURE;
    static std::string MOVEMENT_JAKE;
    static std::string MOVEMENT_SHORT_CASTLING;
    static std::string MOVEMENT_LARGE_CASTLING;
    static std::string MOVEMENT_JAKE_MATE;
    static std::string MOVEMENT_NOTHING;
private:
    std::string result{""};
    Piece* pieceMoved;
};

#endif // MOVEMENTPIECE_H
