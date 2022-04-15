#include <SFML/Graphics.hpp>
#include <vector>
#include "headers\Path.h"
#include "headers\Enemy.h"
#include "headers\SpriteSheet.h"
#include "headers\assets.h"

Enemy::Enemy(int xpos, int ypos, const std::string& type, std::vector<Path>* path) {
    //constructor for enemy type, will use above data to populate enemy object
    this->path = path;
    this->type = type;
    this->ticksSinceFire = 0;
    //placeholder, when more types exist, they will have their data stored in enemy.h
    if (type == "test") {
        this->speed = 0.5;
        this->rateOfFire = 50;
        this->sprite = new SpriteSheet(assets::testEnemy, 1, 1);
    }
 }