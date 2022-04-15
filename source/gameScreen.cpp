#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\gameScreen.h"
#include "headers\assets.h"
#include "headers\Enemy.h"

screenType gameScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the game screen
    processInput(window);
    return game;
}

void gameScreen::draw(sf::RenderWindow* window) {
    //draws gameScreen
    window->clear();
    window->display();
}

gameScreen::gameScreen() {
    //constructor for game screen object.
    this->enemies = new std::vector<Enemy>; //to be replaced by function calling level of enemies from gameData
    //this->bullets = new std::vector<Bullet>; uncomment when bullets are implemented
    //this->Player = new Player(); uncomment when player is implemented
    this->background = new sf::Sprite(assets::stageBackground);
}

gameScreen::~gameScreen() {
    //destructor for game screen object.
}

void gameScreen::processInput(sf::RenderWindow* window) {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) gameData::endProgram = true;
    }
}

void gameScreen::moveEnemies() {
    //moves enemies
}

void gameScreen::movePlayer() {
    //moves the player
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
    //checks if any enemies need to generate shots
}