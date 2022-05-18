#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "headers\Path.h"
#include "headers\Enemy.h"
#include "headers\SpriteSheet.h"
#include "headers\assets.h"
#include "headers\bullet.h"

const float TEST_SPEED = 0.5;
const int TEST_RATE_OF_FIRE = 500;
const std::string TEST_SPRITESHEET = "test_enemy.png";
const std::string TEST_BULLET_TYPE = "";
const float TEST_BULLET_SPEED = 0.5;
const bool TEST_AIM = true;

Enemy::Enemy(int xpos, int ypos, const std::string& type, std::vector<Path*>* path) {
    //constructor for enemy type, will use above data to populate enemy object
    this->path = path;
    this->pathIndex = 0;
    this->path->push_back((new Path(-1, 0.0, 0.0)));
    this->type = type;
    this->ticksSinceFire = 0;
    this->active = false;
    this->defeated = false;

    if (type == "placeholder") {
        //Placeholder for when more typess beyond the default get implemented
    } else {
        this->speed = TEST_SPEED;
        this->rateOfFire = TEST_RATE_OF_FIRE;
        this->sprite = new SpriteSheet(*assets::findAsset(TEST_SPRITESHEET)->texture, 1, 1);
        bulletData.speed = TEST_BULLET_SPEED;
        bulletData.type = TEST_BULLET_TYPE;
        bulletData.aim = TEST_AIM;
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

Bullet* Enemy::generateBullet(sf::Vector2f playerPos) {
    //returns bullet
    sf::Rect<float> position = this->sprite->baseSprite->getGlobalBounds();
    Bullet* placeholder;
    playerPos.x += 12.5;
    playerPos.y += 12.5;

    if (bulletData.aim) {
        float angle = atan2((position.top - playerPos.y), -(position.left - playerPos.x));
        Path* aimPath = new Path(-2, angle, 0.0);
        placeholder = new Bullet(position.left, position.top + position.height, bulletData.speed, bulletData.type, aimPath);
    } else {
        Path* defaultPath = new Path(-2, 3.14159, 0.0);
        placeholder = new Bullet(position.left, position.top + position.height, bulletData.speed, bulletData.type, defaultPath);
    }

    return placeholder;
}
