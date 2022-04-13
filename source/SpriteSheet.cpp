#include <SFML/Graphics.hpp>
#include "headers\SpriteSheet.h"
#include "headers\assets.h"
#include <iostream>

SpriteSheet::SpriteSheet(const sf::Texture& baseTexture, int offset) {
    //constructor for spritesheet
    this->baseSprite = new sf::Sprite(baseTexture);
    this->baseTexture = &baseTexture;
    sf::Vector2u size = baseTexture.getSize();
    this->xOffset = size.x / offset;
    this->height = size.y;
    this->width = size.x;
    this->maxPos = offset;
    this->curPos = 0;
    this->baseSprite->setTextureRect(sf::Rect<int>(curPos * this->xOffset, 0, this->width / this->maxPos, this->height));

}

SpriteSheet::~SpriteSheet() {
    //destructor for spritesheet
    delete this->baseSprite;
}

int SpriteSheet::getPos() {
    //getter for current position of sprite sheet.
    return this->curPos;
}

sf::Sprite* SpriteSheet::getSprite() {
    //getter which retrieves sprite at its current position on the sheet
    return this->baseSprite;
}

void SpriteSheet::nextPos() {
    //function which sets the sprite to the next position
    this->curPos++;
    if (this->curPos >= this->maxPos) this->curPos = 0;
    this->baseSprite->setTextureRect(sf::Rect<int>(curPos * this->xOffset, 0, this->width / this->maxPos, this->height));
}