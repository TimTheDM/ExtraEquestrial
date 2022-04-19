#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "headers\SpriteSheet.h"
#include "headers\player.h"
#include "headers\assets.h"

Player::Player() {
    //constructor for player
    this->playerSprite = new SpriteSheet(assets::playerSprite, 5, 5);
    this->x_offset = 0;
    this->y_offset = 0;
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
