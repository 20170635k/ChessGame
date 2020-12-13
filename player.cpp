#include "player.h"

Player::Player(uint16_t color):color{color}
{

}

uint16_t Player::getColor(){return this->color;}

bool Player::isTurnEnable(){return turnEnable;}
void Player::updateEnableTurn(bool turn){this->turnEnable=turn;}

bool  Player::isJaque(){return this->jaque;}
void Player::setJaque(bool isJaque){this->jaque=isJaque;}
