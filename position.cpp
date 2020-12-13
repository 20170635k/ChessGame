#include "position.h"
Position::Position(uint16_t x, uint16_t y):
    pos_y{y},pos_x{x}
{

}

uint16_t Position::getPosY(){
    return  this->pos_y;
}
void Position::setPosY(uint16_t pos_y){
    this->pos_y=pos_y;
}
uint16_t Position::getPosX(){
    return  this->pos_x;
}
void Position::setPosX(uint16_t pos_x){
    this->pos_x=pos_x;
}
unsigned char Position::parseToChar(uint16_t pos_x){
    unsigned char retorno=' ';
    switch (pos_x) {
        case 1:retorno='a';break;
        case 2:retorno='b';break;
        case 3:retorno='c';break;
        case 4:retorno='d';break;
        case 5:retorno='e';break;
        case 6:retorno='f';break;
        case 7:retorno='g';break;
        case 8:retorno='h';break;
    }
    return retorno;
}
