#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\gameScreen.h"

screenType gameScreen::run() {
    //runs a single game loop of the game screen
    return game;
}

void gameScreen::draw(sf::RenderWindow*) {
    //draws gameScreen
}

gameScreen::gameScreen() {
    //constructor for game screen object.
}

gameScreen::~gameScreen() {
    //destructor for game screen object.
}