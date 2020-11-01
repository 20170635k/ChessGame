#ifndef CASILLERO_H
#define CASILLERO_H

#include <QPushButton>
#include "piece.h"
#include "position.h"
class Casillero:public QPushButton {
public:
    /*constructor*/
    Casillero(unsigned char x,uint16_t y, Piece* piece);
    /*--methods piece---*/
    Piece* getPiece();
    void setPiece(Piece* inpiece);
    void drawPiece();
    /*--methods position--*/
    Position getPosition();
    void setPosition(uint16_t pos_y, unsigned char pos_x);

private:
    Position position;
    Piece* piece{NULL};
};



#endif // CASILLERO_H
