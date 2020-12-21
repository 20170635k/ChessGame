#ifndef HORSE_H
#define HORSE_H

#include "piece.h"
class Horse: public Piece
{
private:
    std::string imagen;
    uint16_t type;
public:
    Horse(uint16_t type);
    bool move(unsigned char x, uint16_t y) override;
    bool kill()override ;
    void setImagen(std::string imagen)override;
    std::string getImagen()override;
    void setType(uint16_t type)override ;
    uint16_t getType()override;
    std::vector<std::vector<int>>posible()override;
    bool movLargo()override;
};

#endif // HORSE_H
