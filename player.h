#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
class Player
{
public:
    Player(uint16_t color);
    bool isJaque();
    void setJaque(bool isJake);
    bool isTurnEnable();
    void updateEnableTurn(bool turn);
    uint16_t getColor();

private:
    bool jaque{false};
    bool turnEnable{false};
    uint16_t color;//
};

#endif // PLAYER_H
