#ifndef CUTSCENE_SCREEN_H
#define CUTSCENE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"
#include "assets.h"
#include "SpriteSheet.h"

class cutsceneScreen : public baseScreen {
    SpriteSheet* background;
    sf::Sprite* cursor;
    sf::Music* titleTheme;
    int cursorPos;
public:
    screenType run();
    void draw(sf::RenderWindow*);
    cutsceneScreen();
    ~cutsceneScreen();
};

#endif //CUTSCENE_SCREEN_H