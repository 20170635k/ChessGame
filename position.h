#ifndef POSITION_H
#define POSITION_H

#include <stdint.h>

class Position{
public:
    Position(uint16_t x, uint16_t y);
    uint16_t getPosY();
    void setPosY(uint16_t pos_y);
    uint16_t getPosX();
    void setPosX(uint16_t pos_x);
    unsigned char parseToChar(uint16_t pos_x);
private:
   uint16_t pos_y;
   uint16_t pos_x;
};

#endif // POSITION_H
