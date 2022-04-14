#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Path.h"

class enemy {
    //class that stores data for an enemy object
    sf::Texture* enemyTexture;
    std::vector<Path>* path;
    std::string type;
public:
    enemy(int, int, const std::string&, std::vector<Path>*);
    ~enemy();
};

#endif //ENEMY_H