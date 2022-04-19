#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteSheet.h"

class Player {
    //Class for holding player data
public:
    SpriteSheet* playerSprite;
    void movePlayer();
    float x_offset;
    float y_offset;
    Player();
    ~Player();
};

#endif //PLAYER_H