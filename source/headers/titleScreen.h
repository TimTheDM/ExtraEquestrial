#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"

class titleScreen: public baseScreen {

public:
    screenType run();
    void draw(sf::RenderWindow*);
    titleScreen();
    ~titleScreen();
};

#endif //titleScreen.h