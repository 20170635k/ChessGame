#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include <string>
#include <vector>
#include "Position.h"

class Piece{
public:
    static uint16_t TYPE_WHITE;
    static uint16_t TYPE_BLACK;
    virtual bool move(unsigned char x, uint16_t y)=0;
    virtual bool kill()=0;
    virtual void setImagen(std::string imagen)=0;
    virtual std::string getImagen()=0;
    virtual void setType(uint16_t type)=0;
    virtual uint16_t getType()=0;
protected:
    std::vector<Position> possiblemoves;
    std::string imagen;
    uint16_t type;
};

#endif // PIECE_H
