#include <SFML/Graphics.hpp>
#include "headers\SpriteSheet.h"

SpriteSheet::SpriteSheet(const sf::Texture& baseTexture, int offset) {
    //constructor for spritesheet
}

SpriteSheet::~SpriteSheet() {
    //destructor for spritesheet
    delete this->baseSprite;
}

int SpriteSheet::getPos() {
    //getter for current position of sprite sheet.
}

sf::Sprite* SpriteSheet::getSprite() {
    //getter which retrieves sprite at its current position on the sheet
}

void SpriteSheet::nextPos() {
    //function which sets the sprite to the next position
}