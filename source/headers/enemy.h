#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Path.h"
#include "SpriteSheet.h"

class Enemy {
    //class that stores data for an enemy object
    SpriteSheet* sprite;
    std::vector<Path>* path;
    std::string type;
    float speed;
    int rateOfFire;
    int ticksSinceFire;
public:
    Enemy(int, int, const std::string&, std::vector<Path>*);
    ~Enemy();
};

#endif //ENEMY_H