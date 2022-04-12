#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\titleScreen.h"

screenType titleScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the title screen
    window->clear();
    window->display();
    return title;
}

titleScreen::titleScreen() {
    //constructor for title screen object.
}