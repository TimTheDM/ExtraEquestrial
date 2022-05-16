#include <SFML/Graphics.hpp>
#include <vector>
#include "headers\Path.h"
#include "headers\Enemy.h"
#include "headers\SpriteSheet.h"
#include "headers\assets.h"
#include "headers\bullet.h"

Enemy::Enemy(int xpos, int ypos, const std::string& type, std::vector<Path*>* path) {
    //constructor for enemy type, will use above data to populate enemy object
    this->path = path;
    this->pathIndex = 0;
    this->path->push_back((new Path(-1, 0.0, 0.0)));
    this->type = type;
    this->ticksSinceFire = 0;
    this->active = false;
    this->defeated = false;
    //placeholder, when more types exist, they will have their data stored in enemy.h
    if (type == "test") {
        this->speed = 0.5;
        this->rateOfFire = 1500;
        this->sprite = new SpriteSheet(*assets::findAsset("test_enemy.png")->texture, 1, 1);
    }
    this->sprite->baseSprite->move(xpos, ypos);
}

Enemy::~Enemy() {
    delete this->sprite;
    delete this->path;
}

void Enemy::moveEnemy() {
    this->sprite->getSprite()->move(this->path->at(this->pathIndex)->retrieve_x_offset() * this->speed, this->path->at(this->pathIndex)->retrieve_y_offset() * this->speed);
}

void Enemy::pathTick() {
    //moves down tick of current path, increments pathIndex if isDone of path returns true
    this->path->at(this->pathIndex)->incrementPath();
    if (this->path->at(this->pathIndex)->isDone()) this->pathIndex++;
}

void Enemy::resetBullet() {
    this->ticksSinceFire = 0;
}

void Enemy::incrementBullet() {
    this->ticksSinceFire++;
}

bool Enemy::readyToFire() {
    //returns if bullet is ready to fire or not
    return (this->ticksSinceFire >= this->rateOfFire);
}

Bullet* Enemy::generateBullet() {
    //returns bullet
    sf::Rect<float> position = this->sprite->baseSprite->getGlobalBounds();
    Path* defaultPath = new Path(-2, 3.14159, 0.0);
    Bullet* placeholder = new Bullet(position.left, position.top + position.height, "test", defaultPath);
    return placeholder;
}
