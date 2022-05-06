#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "SpriteSheet.h"
#include "Bullet.h"
#include "path.h"

class Player {
    //Class for holding player data
    int invulnTimer;
    int invulnTime;
    int bulletTime;
    int bulletTimer;
    bool isMakeBullet;
public:
    SpriteSheet* playerSprite;
    bool hit;
    bool draw;
    bool readyMakeBullet();
    void shoot();
    Bullet* makeBullet();
    void bulletCooldown();
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