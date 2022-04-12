#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\titleScreen.h"

screenType titleScreen::run() {
    //runs a single game loop of the title screen
    return title;
}

void titleScreen::draw(sf::RenderWindow*) {
    //draws titleScreen
}

titleScreen::titleScreen() {
    //constructor for title screen object.
}