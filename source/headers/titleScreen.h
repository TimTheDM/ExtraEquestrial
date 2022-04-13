#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"
#include "assets.h"
#include "SpriteSheet.h"

class TitleScreen : public baseScreen {
    SpriteSheet* background;
    sf::Sprite* cursor;
    sf::Music* titleTheme;
    int cursorPos;
public:
    screenType run();
    void draw(sf::RenderWindow*);
    void processEvent(const sf::Event&);
    TitleScreen();
    ~TitleScreen();
};

#endif //TITLE_SCREEN_H