#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "SpriteSheet.h"

class Player {
    //Class for holding player data
    int invulnTimer;
    int invulnTime;
public:
    SpriteSheet* playerSprite;
    bool hit;
    bool draw;
    int getTime();
    bool isInvuln();
    void makeInvuln();
    void invulnTick();
    void movePlayer();
    void joystickShift();
    float x_offset;
    float y_offset;
    Player();
    ~Player();
};

#endif //PLAYER_H