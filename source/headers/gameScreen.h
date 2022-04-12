#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "baseScreen.h"

class gameScreen {

public:
    screenType run();
    void draw(sf::RenderWindow*);
    gameScreen();
    ~gameScreen();
};

#endif //GAME_SCREEN_H