#ifndef POSITION_H
#define POSITION_H


#include <stdint.h>

class Position{
public:
    uint16_t getPosY();
    void setPosY(uint16_t pos_y);
    unsigned char getPosX();
    void setPosX(unsigned char pos_x);
private:
   uint16_t pos_y;
   unsigned char pos_x;
};

#endif // POSITION_H
