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
    //this->cursorSprite = new Sf::Sprite(cursor texture);
    this->titleTheme = &assets::titleMusic;
    this->background = new SpriteSheet(assets::titleBackground, 8);
    this->cursorPos = 0;
}

TitleScreen::~TitleScreen() {
    //destructor for title screen object.
}

void TitleScreen::processEvent(const sf::Event&) {
    //processes events, and runs the proper checks for them
}