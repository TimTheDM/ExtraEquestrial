#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"

class gameScreen : public baseScreen {

public:
    screenType run(sf::RenderWindow*);
    void draw(sf::RenderWindow*);
    gameScreen();
    ~gameScreen();
};

#endif //GAME_SCREEN_H