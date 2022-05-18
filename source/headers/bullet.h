#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "path.h"

class Bullet {
    Path* bulletPath;
    float speed;
    std::string type;
public:
    sf::Sprite* bulletSprite;
    Bullet(float, float, float, const std::string&, Path*);
    ~Bullet();
    void moveBullet();
    bool isActive;
};

#endif //BULLET_H