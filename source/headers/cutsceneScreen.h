#ifndef CUTSCENE_SCREEN_H
#define CUTSCENE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"

class cutsceneScreen : public baseScreen {

public:
    screenType run();
    void draw(sf::RenderWindow*);
    cutsceneScreen();
    ~cutsceneScreen();
};

#endif //CUTSCENE_SCREEN_H