#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"

class titleScreen: public baseScreen {

public:
    screenType run(sf::RenderWindow*);
    titleScreen();
};

#endif //titleScreen.h