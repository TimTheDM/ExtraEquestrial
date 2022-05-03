#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Path.h"
#include "SpriteSheet.h"
#include "bullet.h"

class Enemy {
    //class that stores data for an enemy object
    std::vector<Path*>* path;
    std::string type;
    float speed;
    int pathIndex;
    int rateOfFire;
    int ticksSinceFire;
public:
    bool active;
    SpriteSheet* sprite;
    Enemy(int, int, const std::string&, std::vector<Path*>*);
    ~Enemy();
    Bullet* generateBullet();
    void resetBullet();
    void incrementBullet();
    bool readyToFire();
    void moveEnemy();
    void pathTick();
};

#endif //ENEMY_H