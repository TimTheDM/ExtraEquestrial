#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include <SFML/Graphics.hpp>

class SpriteSheet {
//class for storing data on a sprite that must cycle through a vertically aligned sprite sheet
    int maxPos;
    int curPos;
    int xOffSet;
    sf::Sprite* baseSprite;
    sf::Texture* baseTexture;
public:
    int getPos();
    sf::Sprite* getSprite();
    void nextPos();
    SpriteSheet(const sf::Texture&, int);
    ~SpriteSheet();
};

#endif SPRITE_SHEET_H 