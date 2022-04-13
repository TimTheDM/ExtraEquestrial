#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include <SFML/Graphics.hpp>

class SpriteSheet {
//class for storing data on a sprite that must cycle through a vertically aligned sprite sheet
    int maxPos;
    int curPos;
    int xOffset;
    int height;
    int width;
    int ticksBetween;
    int tickCount;
    const sf::Texture* baseTexture;
public:
    sf::Sprite* baseSprite;
    int getPos();
    sf::Sprite* getSprite();
    void nextPos();
    SpriteSheet(const sf::Texture&, int, int);
    ~SpriteSheet();
};

#endif //SPRITE_SHEET_H 