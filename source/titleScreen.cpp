#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\TitleScreen.h"
#include "headers\assets.h"
#include "headers\SpriteSheet.h"

screenType TitleScreen::run() {
    //runs a single game loop of the title screen
    return title;
}

void TitleScreen::draw(sf::RenderWindow*) {
    //draws titleScreen
}

TitleScreen::TitleScreen() {
    //constructor for title screen object.
}

TitleScreen::~TitleScreen() {
    //destructor for title screen object.
}