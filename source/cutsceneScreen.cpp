#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\cutsceneScreen.h"

screenType cutsceneScreen::run() {
    //runs a single game loop of the cutscene screen
    return cutscene;
}

void cutsceneScreen::draw(sf::RenderWindow*) {
    //draws cutscene
}

cutsceneScreen::cutsceneScreen() {
    //constructor for cutscene screen object.
}

cutsceneScreen::~cutsceneScreen() {
    //destructor for cutscene screen object.
}