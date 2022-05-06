#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "headers\SpriteSheet.h"
#include "headers\player.h"
#include "headers\assets.h"
#include "headers\Bullet.h"
#include "headers\path.h"

const int INVULN_FRAMES = 240;
const int INVULN_FRAME_FLASH = 8;
const int TICKS_BETWEEN_SHOTS = 60;

Player::Player() {
    //constructor for player
    this->playerSprite = new SpriteSheet(assets::playerSprite, 5, 15);
    this->x_offset = 0;
    this->y_offset = 0;
    this->invulnTimer = INVULN_FRAMES;
    this->invulnTime = INVULN_FRAMES;
    this->bulletTime = TICKS_BETWEEN_SHOTS;
    this->bulletTimer = TICKS_BETWEEN_SHOTS;
    this->hit = false;
    this->draw = false;
    this->isMakeBullet = false;
    this->playerSprite->baseSprite->setScale(0.5, 0.5);
}

Player::~Player() {
    //destructor  for player
    delete this->playerSprite;
}

void Player::movePlayer() {
    //moves player by offsets
    this->playerSprite->baseSprite->move(this->x_offset, this->y_offset);
}

void Player::joystickShift() {
    //shifts private offset members according to joystick at index joystickIndex
    sf::Joystick::update();

    float x_axis = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float y_axis = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

    if ((x_axis > 0.1 || x_axis < -0.1) || (y_axis > 0.1 || y_axis < -0.1)) {
        float angle = atan(y_axis / x_axis);
        this->x_offset = cos(angle);
        this->y_offset = sin(angle);

        if (x_axis < 0.f && this->x_offset > 0) this->x_offset *= -1.f;
        if (x_axis > 0.f && this->x_offset < 0) this->x_offset *= -1;
        if (y_axis < 0.f && this->y_offset > 0) this->y_offset *= -1.f;
        if (y_axis > 0.f && this->y_offset < 0) this->y_offset *= -1;
    } else {
        this->x_offset = 0;
        this->y_offset = 0;
    }
}

bool Player::isInvuln() {
    if (this->invulnTimer < this->invulnTime) return true;
    else return false;
}

void Player::makeInvuln() {
    this->invulnTimer = 0;
    this->draw = false;
}

void Player::invulnTick() {
    if (this->invulnTimer != this->invulnTime) this->invulnTimer++;
    if (this->invulnTimer % INVULN_FRAME_FLASH == 0) {
        if (this->draw) this->draw = false;
        else this->draw = true;
    }
}

int Player::getTime() {
    return this->invulnTimer;
}

bool Player::readyMakeBullet() {
    return this->isMakeBullet;
}

void Player::shoot() {
    if (this->bulletTimer == this->bulletTime) this->isMakeBullet = true;
}

void Player::bulletCooldown() {
    if (this->bulletTimer < this->bulletTime) this->bulletTimer++;
}

Bullet* Player::makeBullet() {
    this->isMakeBullet = false;
    this->bulletTimer = 0;
    sf::Vector2f playerPos = this->playerSprite->baseSprite->getPosition();
    return new Bullet(playerPos.x, playerPos.y, "player", new Path(-2, 0.0, 0.0));
}