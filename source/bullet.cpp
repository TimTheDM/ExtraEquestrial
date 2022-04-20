#include <SFML/Graphics.hpp>
#include "headers\path.h"
#include "headers\bullet.h"
#include "headers\assets.h"

Bullet::Bullet(float xpos, float ypos, const std::string& type, Path* bPath) {
    this->bulletPath = bPath;
    this->type = type;
    this->isActive = true;
    //will change when more types are implemented
    if (type == "test") {
        this->bulletSprite = new sf::Sprite(assets::testBullet);
        this->speed = 0.5;
        this->bulletSprite->move(xpos, ypos);
    }
}

Bullet::~Bullet() {
    delete this->bulletPath;
    delete this->bulletSprite;
}

void Bullet::moveBullet() {
    this->bulletSprite->move(this->bulletPath->retrieve_x_offset(), this->bulletPath->retrieve_y_offset());
}