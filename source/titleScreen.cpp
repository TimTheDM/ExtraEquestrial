#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\TitleScreen.h"
#include "headers\assets.h"
#include "headers\SpriteSheet.h"

const int CURSOR_X_OFFSET = 9;
const int CURSOR_Y_OFFSET = 24;

screenType TitleScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the title screen
    screenType returnScreen = title;

    sf::Event event;
    while (window->pollEvent(event)) {
        returnScreen = this->processEvent(event);
        if (returnScreen == game) break;
    }

    if (returnScreen == game) {
        this->titleTheme->stop();
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

screenType TitleScreen::processEvent(const sf::Event& event) {
    //processes events, and runs the proper checks for them
    if (event.type == sf::Event::Closed) gameData::endProgram = true;
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
            if (this->cursorPos == 0) {
                this->cursorPos = 1;
                this->cursor->move(CURSOR_X_OFFSET, CURSOR_Y_OFFSET);
            } else {
                this->cursorPos = 0;
                this->cursor->move(-CURSOR_X_OFFSET, -CURSOR_Y_OFFSET);
            }
        } else if (event.key.code == sf::Keyboard::Z) {
            if (this->cursorPos == 0) {
                return game;
            }
            else gameData::endProgram = true;
        }
    }
    return title;
}