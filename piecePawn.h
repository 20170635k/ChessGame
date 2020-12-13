#ifndef PAWN_H
#define PAWN_H


#include "piece.h"
class Pawn: public Piece
{
private:
    std::string imagen;
    uint16_t type;
public:
    Pawn(uint16_t type);
    bool move(unsigned char x, uint16_t y) override;
    bool kill()override ;
    void setImagen(std::string imagen)override;
    std::string getImagen()override;
    void setType(uint16_t type)override ;
    uint16_t getType()override;
};

#endif // PAWN_H
