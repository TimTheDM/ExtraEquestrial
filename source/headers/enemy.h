#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "path.h"

class enemy {
    //class that stores data for an enemy object
    sf::Texture* enemyTexture;
    std::vector<path>* path;
    std::string type;
public:
    enemy(int, int, const std::string&, sf::Vector2f*);
    ~enemy();
};

#endif //ENEMY_H