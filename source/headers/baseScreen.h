#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

#include <SFML/Graphics.hpp>

enum screenType {title, game, cutscene};

class baseScreen {
    //base abstract class for a screen of the game, contains only members shared by every screen
public:
    virtual screenType run(sf::RenderWindow*) = 0;
    virtual void draw(sf::RenderWindow*) = 0;
};

#endif //BASE_SCREEN_H