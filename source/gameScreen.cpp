#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\gameScreen.h"

screenType gameScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the game screen
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) gameData::endProgram = true;
    }
    return game;
}

void gameScreen::draw(sf::RenderWindow* window) {
    //draws gameScreen
    window->clear();
    window->display();
}

gameScreen::gameScreen() {
    //constructor for game screen object.
}

gameScreen::~gameScreen() {
    //destructor for game screen object.
}