#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>
#include <string>
#include <vector>
#include "position.h"
#include <iostream>

class Piece{

public:
    Piece(std::string code);
    virtual ~Piece();
    static uint16_t TYPE_WHITE;
    static uint16_t TYPE_BLACK;
    static std::string PIECE_CODE_HORSE;
    static std::string PIECE_CODE_ALFIL;
    static std::string PIECE_CODE_KING;
    static std::string PIECE_CODE_QUEEN;
    static std::string PIECE_CODE_PAWN;
    static std::string PIECE_CODE_TOWER;

    //si no escuentras utilidad al método move o kill lo borras y agregas tus métodos
    virtual bool move(unsigned char x, uint16_t y){return true;};//aun no se definio el uso
    virtual bool kill(){return true;};// aun no se definió el uso
    virtual void setImagen(std::string imagen){this->imagen=imagen;};
    virtual std::string getImagen(){return imagen;};
    virtual void setType(uint16_t type){this->type=type;};
    virtual uint16_t getType(){return 0;};

    virtual void setPosition(uint16_t x, uint16_t y);
    virtual Position* getPosition();

    virtual bool movLargo(){return true;};
    virtual std::vector<std::vector<int>> posible();
    bool firstMove=true;
    virtual std::string getPieceCode();
    std::string nombre;
protected:
    Position*position;// para guardar los posibles movimientos de una pieza aun no está implementado
    std::string imagen;//guarda imagen de la pieza
    uint16_t type;//guarda el tipo ya sea blanco o negro
    std::string codePiece;

};

#endif // PIECE_H
