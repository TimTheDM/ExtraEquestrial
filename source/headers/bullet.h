#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "path.h"

class Bullet {
    bool isActive;
    Path* bulletPath;
    float x_offset;
    float y_offset;
    float speed;
    std::string type;
public:
    sf::Sprite* bulletSprite;
    Bullet(int, int, const std::string&, Path*);
    ~Bullet();
    void moveBullet();
};

#endif //BULLET_H