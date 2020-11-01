#include "position.h"

uint16_t Position::getPosY(){
    return  this->pos_y;
}
void Position::setPosY(uint16_t pos_y){
    this->pos_y=pos_y;
}
unsigned char Position::getPosX(){
    return  this->pos_x;
}
void Position::setPosX(unsigned char pos_x){
    this->pos_x=pos_x;
}
