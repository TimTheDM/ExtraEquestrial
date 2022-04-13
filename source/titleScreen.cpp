#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\TitleScreen.h"
#include "headers\assets.h"
#include "headers\SpriteSheet.h"

const sf::Vector2f CURSOR_START(150, 100);

screenType TitleScreen::run() {
    //runs a single game loop of the title screen
    return title;
}

void TitleScreen::draw(sf::RenderWindow* window) {
    //draws titleScreen
    window->draw( *(this->background->getSprite()) );
    //window->draw(this->cursor);

}

TitleScreen::TitleScreen() {
    //constructor for title screen object.
    //this->cursorSprite = new Sf::Sprite(cursor texture);
    this->titleTheme = &assets::titleMusic;
    this->background = new SpriteSheet(assets::titleBackground, 8);
    this->cursorPos = 0;
    //this->cursorSprite.setPosition(CURSOR_START);
}

TitleScreen::~TitleScreen() {
    //destructor for title screen object.
    delete this->background;
    delete this->cursor;
}

void TitleScreen::processEvent(const sf::Event&) {
    //processes events, and runs the proper checks for them
}