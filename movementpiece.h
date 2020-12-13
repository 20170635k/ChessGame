#ifndef MOVEMENTPIECE_H
#define MOVEMENTPIECE_H
#include "position.h"
#include "piece.h"
#include <QTextEdit>
class MovementPiece
{
public:
    MovementPiece();

    void setPieceMoved(Piece* piecemoved);
    Piece* getPieceModed();
    void addItemDescMovement(std::string itemdes);
    QString formatString();
private:
    std::vector<std::string>movement;
    Piece* pieceMoved;
};

#endif // MOVEMENTPIECE_H
