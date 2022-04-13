#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\TitleScreen.h"
#include "headers\assets.h"
#include "headers\SpriteSheet.h"

const sf::Vector2f CURSOR_START(150, 100);

screenType TitleScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the title screen
    screenType returnScreen = title;

    sf::Event event;
    while (window->pollEvent(event)) {
        processEvent(event);
    }

    return returnScreen;
}

void TitleScreen::draw(sf::RenderWindow* window) {
    //draws titleScreen
    this->background->nextPos();
    window->clear();
    window->draw( *(this->background->getSprite()) );
    window->draw(*this->play);
    window->draw(*this->exit);
    window->draw(*this->cursor);
    window->display();

}

TitleScreen::TitleScreen() {
    //constructor for title screen object.
    this->cursor = new sf::Sprite(assets::cursor);
    this->play = new sf::Sprite(assets::playSymbol);
    this->exit = new sf::Sprite(assets::exitSymbol);
    this->titleTheme = &assets::titleMusic;
    this->background = new SpriteSheet(assets::titleBackground, 8, 5);
    this->cursorPos = 0;
    this->titleTheme->setLoop(true);
    this->titleTheme->play();
    //this->cursorSprite.setPosition(CURSOR_START);
}

TitleScreen::~TitleScreen() {
    //destructor for title screen object.
    delete this->background;
    delete this->cursor;
    delete this->play;
    delete this->exit;
}

void TitleScreen::processEvent(const sf::Event&) {
    //processes events, and runs the proper checks for them
}