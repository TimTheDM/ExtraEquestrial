#include <iostream>
#include <SFML/Graphics.hpp>
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