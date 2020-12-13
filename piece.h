#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include <string>
#include <vector>
#include "position.h"
#include <iostream>

class Piece{
public:

    Piece();
    virtual ~Piece();
    static uint16_t TYPE_WHITE;
    static uint16_t TYPE_BLACK;

    //si no escuentras utilidad al método move o kill lo borras y agregas tus métodos
    virtual bool move(unsigned char x, uint16_t y){return true;};//aun no se definio el uso
    virtual bool kill(){return true;};// aun no se definió el uso
    virtual void setImagen(std::string imagen){this->imagen=imagen;};
    virtual std::string getImagen(){return imagen;};
    virtual void setType(uint16_t type){this->type=type;};
    virtual uint16_t getType(){return 0;};
protected:
    std::vector<Position> possiblemoves;// para guardar los posibles movimientos de una pieza aun no está implementado
    std::string imagen;//guarda imagen de la pieza
    uint16_t type;//guarda el tipo ya sea blanco o negro
};

#endif // PIECE_H
