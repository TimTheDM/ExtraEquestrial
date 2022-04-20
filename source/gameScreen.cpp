#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\gameScreen.h"
#include "headers\assets.h"
#include "headers\Enemy.h"
#include "headers\player.h"

screenType gameScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the game screen
    processInput(window);
    movePlayer();
    moveEnemies();
    moveBullets();
    checkCollision();
    generateBullets();
    return game;
}

void gameScreen::draw(sf::RenderWindow* window) {
    //draws gameScreen
    window->clear();
    window->draw(*this->background);
    for (int i = 0; i < this->enemies->size();i++) {
        window->draw(*this->enemies->at(i).sprite->baseSprite);
    }
    window->draw(*this->player->playerSprite->baseSprite);
    this->player->playerSprite->nextPos();
    window->display();
}

gameScreen::gameScreen() {
    //constructor for game screen object.
    this->enemies = new std::vector<Enemy>; //to be replaced by function calling level of enemies from gameData
    std::vector<Path>* testPath = new std::vector<Path>;
    testPath->push_back(*(new Path(-1, 0.0, 0.03)));
    this->enemies->push_back(*(new Enemy(200, 100, "test", testPath)));
    //this->bullets = new std::vector<Bullet>; uncomment when bullets are implemented
    this->player = new Player();
    this->background = new sf::Sprite(assets::stageBackground);
}

gameScreen::~gameScreen() {
    //destructor for game screen object.
    for (int i = 0;i < this->enemies->size();i++) {
        delete &this->enemies->at(i);
    }
    delete this->enemies;
    delete this->background;
    //delete this->bullets;
    delete this->player;
}

void gameScreen::processInput(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) gameData::endProgram = true;
    }

    this->player->joystickShift();
}

void gameScreen::moveEnemies() {
    //moves enemies
    for (int i = 0;i < this->enemies->size();i++) {
        this->enemies->at(i).moveEnemy();
        this->enemies->at(i).pathTick();
    }
}

void gameScreen::movePlayer() {
    //moves the player
    this->player->movePlayer();
}

void gameScreen::moveBullets() {
    //moves bullets
}

void gameScreen::checkCollision() {
    //checks for collision between objects
}

void gameScreen::playerCollide() {
    //Called when player sprite intersects with a bullet sprite
}

void gameScreen::generateBullets() {
    //checks if any enemies need to generate bullets, resets their bullet timers
}