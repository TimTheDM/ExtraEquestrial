#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Path.h"

class Enemy {
    //class that stores data for an enemy object
    sf::Texture* enemyTexture;
    std::vector<Path>* path;
    std::string type;
public:
    Enemy(int, int, const std::string&, std::vector<Path>*);
    ~Enemy();
};

#endif //ENEMY_H