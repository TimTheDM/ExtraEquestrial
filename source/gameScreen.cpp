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
#include "headers\bullet.h"

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
        window->draw(*this->enemies->at(i)->sprite->baseSprite);
    }
    for (int i = 0;i < this->bullets->size();i++) {
        window->draw(*this->bullets->at(i)->bulletSprite);
    }
    window->draw(*this->player->playerSprite->baseSprite);
    window->draw(*this->player->hitbox);
    this->player->playerSprite->nextPos();
    window->display();
}

gameScreen::gameScreen() {
    //constructor for game screen object.
    this->enemies = new std::vector<Enemy*>; //to be replaced by function calling level of enemies from gameData
    this->bullets = new std::vector<Bullet*>;
    std::vector<Path*>* testPath = new std::vector<Path*>;
    testPath->push_back((new Path(-1, 0.0, 0.03)));
    this->enemies->push_back((new Enemy(200, 100, "test", testPath)));
    this->player = new Player();
    this->background = new sf::Sprite(assets::stageBackground);
}

gameScreen::~gameScreen() {
    //destructor for game screen object.
    for (int i = 0;i < this->enemies->size();i++) {
        delete this->enemies->at(i);
    }
    delete this->enemies;
    delete this->background;
    delete this->bullets;
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
        this->enemies->at(i)->moveEnemy();
        this->enemies->at(i)->pathTick();
    }
}

void gameScreen::movePlayer() {
    //moves the player
    this->player->movePlayer();
}

void gameScreen::moveBullets() {
    //moves bullets
    for (int i = 0;i < this->bullets->size();i++) {
        if (this->bullets->at(i)->isActive) {
            this->bullets->at(i)->moveBullet();
        }
    }
}

void gameScreen::checkCollision() {
    //checks for collision between objects
    sf::Vector2f playerPos(this->player->playerSprite->baseSprite->getPosition());
    int pRadius = this->player->playerSprite->baseSprite->getLocalBounds().width / 2;
    playerPos.x = playerPos.x + (this->player->playerSprite->baseSprite->getLocalBounds().width / 2);
    playerPos.y = playerPos.y + (this->player->playerSprite->baseSprite->getLocalBounds().height / 2);

    for (int i = 0;i < this->bullets->size();i++) {
        sf::Vector2f bulletPos(this->bullets->at(i)->bulletSprite->getPosition());
        int bRadius = this->bullets->at(i)->bulletSprite->getLocalBounds().width / 2;
        bulletPos.x = bulletPos.x + (this->bullets->at(i)->bulletSprite->getLocalBounds().width / 2);
        bulletPos.y = bulletPos.y + (this->bullets->at(i)->bulletSprite->getLocalBounds().height / 2);
        if (this->doesCollide(playerPos, pRadius, bulletPos, bRadius)) {
            this->playerCollide();
        }
    }
}

bool gameScreen::doesCollide(const sf::Vector2f& playerPos, int playerRadius, const sf::Vector2f& bulletPos, int bulletRadius) {
    float distance = sqrt(std::pow((playerPos.x - bulletPos.x), 2) + std::pow(playerPos.y - bulletPos.y, 2));
    if ( (playerRadius + bulletRadius) > distance ) {
        std::cout << "Collide!\n";
        return true;
    } else return false;
}

void gameScreen::playerCollide() {
    //Called when player sprite intersects with a bullet sprite
}

void gameScreen::generateBullets() {
    //checks if any enemies need to generate bullets, resets their bullet timers
    for (int i = 0;i < this->enemies->size();i++) {
        if (this->enemies->at(i)->readyToFire()) {
            this->bullets->push_back(this->enemies->at(i)->generateBullet());
            this->enemies->at(i)->resetBullet();
        } else {
            this->enemies->at(i)->incrementBullet();
        }
    }
}