#ifndef CUTSCENE_SCREEN_H
#define CUTSCENE_SCREEN_H

#include <SFML/Graphics.hpp>
#include "baseScreen.h"
#include "assets.h"
#include "SpriteSheet.h"

class cutsceneScreen : public baseScreen {
public:
    screenType run(sf::RenderWindow*);
    void draw(sf::RenderWindow*);
    cutsceneScreen();
    ~cutsceneScreen();
};

#endif //CUTSCENE_SCREEN_H