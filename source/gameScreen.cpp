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
#include "headers\event.h"
#include "headers\interpreter.h"

const bool DISPLAY_HITBOX = true;
const float SCROLL_SPEED = 0.05;
const bool WILL_SCROLL = true;
const int START_X = 40;
const int START_Y = 76;

screenType gameScreen::run(sf::RenderWindow* window) {
    //runs a single game loop of the game screen
    processInput(window);
    moveView(window);
    manageEvents();
    manageActive();
    managePlayer();
    moveEnemies();
    moveBullets();
    checkCollision();
    generateBullets();
    return screenManage(window);
}

void gameScreen::draw(sf::RenderWindow* window) {
    //draws gameScreen
    window->clear();

    //Draw the background
    drawBackground(window);

    //Draw all enemies, bullets, and the player
    for (int i = 0; i < this->enemies->size();i++) {
        if (this->enemies->at(i)->active) window->draw(*this->enemies->at(i)->sprite->baseSprite);
    }

    for (int i = 0;i < this->bullets->size();i++) {
        window->draw(*this->bullets->at(i)->bulletSprite);
    }

    for (int i = 0;i < this->pBullets->size();i++) {
        window->draw(*this->pBullets->at(i)->bulletSprite);
    }

    if (this->player->isInvuln()) {
        if (this->player->draw) {
            window->draw(*this->player->playerSprite->baseSprite);
        }
    } else {
        window->draw(*this->player->playerSprite->baseSprite);
    }

    for (int i = 0;i < this->events->size();i++) {
        if (events->at(i)->isActive() && events->at(i)->getType() == animation) {
            window->draw(*events->at(i)->animationSheet->baseSprite);
        }
    }

    //draw the hitboxes if in hitbox mode
    if (DISPLAY_HITBOX) {
        sf::CircleShape hitbox;
        hitbox.setRadius(this->player->playerSprite->baseSprite->getLocalBounds().width / 2);
        sf::Vector2f circlePos(this->player->playerSprite->baseSprite->getPosition());
        hitbox.setPosition(circlePos);
        hitbox.setScale(0.5, 0.5);
        hitbox.setFillColor(sf::Color(5, 5, 5, 150));
        window->draw(hitbox);
        if (this->isCollide) {
            //sf::Sprite collideConfirm(assets::testEnemy);
            //window->draw(collideConfirm);
        }

        for (int i = 0;i < this->bullets->size();i++) {
            sf::CircleShape hitbox;
            hitbox.setRadius(this->bullets->at(i)->bulletSprite->getLocalBounds().width / 2);
            sf::Vector2f bulletPos(this->bullets->at(i)->bulletSprite->getPosition());
            hitbox.setPosition(bulletPos);
            hitbox.setFillColor(sf::Color(5, 5, 5, 150));
            window->draw(hitbox);
        }
    }

    //update spriteSheet animations
    this->player->playerSprite->nextPos();
    window->display();
}

void gameScreen::drawBackground(sf::RenderWindow* window) {
    //draws the background
    background->setPosition((gameData::screenWidth * ((static_cast<int>(gameView->getCenter().x) - (gameData::screenWidth / 2)) / gameData::screenWidth)) , 0);
    window->draw(*background);
    background->move(gameData::screenWidth, 0);
    window->draw(*background);
}

gameScreen::gameScreen() {
    //constructor for game screen object.
    this->enemies = interpret(std::string("levels\\") + "level" + std::to_string(gameData::level) + ".lvl");
    this->bullets = new std::vector<Bullet*>;
    this->pBullets = new std::vector<Bullet*>;
    this->events = new std::vector<Event*>;
    this->player = new Player();
    this->background = new sf::Sprite(*assets::findAsset("Stage_Background.png")->texture);
    this->gameView = new sf::View(sf::Vector2f(gameData::screenWidth / 2, gameData::screenLength / 2), sf::Vector2f(gameData::screenWidth, gameData::screenLength));
    this->isScroll = WILL_SCROLL;
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

    if (sf::Joystick::isButtonPressed(0, 2)) {
        this->player->shoot();
    }

    this->player->joystickShift();
}

void gameScreen::moveView(sf::RenderWindow* window) {
    //moves view by SCROLL_SPEED every game tick
    window->setView(*this->gameView);
    if (this->isScroll) this->gameView->move(SCROLL_SPEED, 0);
}

void gameScreen::managePlayer() {
    //function for managing players movement, bullets, and invuln state
    movePlayer();
    
    if (this->player->readyMakeBullet()) {
        this->pBullets->push_back(this->player->makeBullet());
        std::cout << "Bang!";
    } else {
        this->player->bulletCooldown();
    }

    if (this->player->isInvuln()) {
        this->player->invulnTick();
    }

    if (this->player->hit) {
        //logic for when player is struck
        std::cout << "I'm hit!";
        this->player->makeInvuln();
        this->player->playerSprite->baseSprite->setPosition(START_X + this->gameView->getCenter().x - (gameData::screenWidth / 2), START_Y);
        this->player->hit = false;
    }
}

void gameScreen::manageActive() {
    //function that activates and deactives enemies depending on where the view is
    float widthMiddle = this->gameView->getCenter().x;
    float halfScreenWidth = gameData::screenWidth / 2;

    for (int i = 0;i < this->enemies->size();i++) {
        float enemyXPos = this->enemies->at(i)->sprite->baseSprite->getPosition().x;
        int enemyWidth = this->enemies->at(i)->sprite->baseSprite->getLocalBounds().width;
        if (this->enemies->at(i)->active && (enemyXPos + enemyWidth) < (widthMiddle - halfScreenWidth)) {
            std::cout << "Set deActive\n";
            this->enemies->at(i)->active = false;
        } else if (this->enemies->at(i)->active == false && enemyXPos < (widthMiddle + halfScreenWidth) && (enemyXPos - enemyWidth) > (widthMiddle - halfScreenWidth) && this->enemies->at(i)->defeated == false) {
            std::cout << "Set Active\n";
            this->enemies->at(i)->active = true;
        }
    }
}

void gameScreen::manageEvents() {
    //function that manages the vector of events
    for (int i = 0;i < events->size();i++) {
        if (events->at(i)->isActive()) {
            events->at(i)->tick();
        }
    }
}

void gameScreen::moveEnemies() {
    //moves enemies
    for (int i = 0;i < this->enemies->size();i++) {
        if (this->enemies->at(i)->active) {
            this->enemies->at(i)->moveEnemy();
            this->enemies->at(i)->pathTick();
        }
    }
}

void gameScreen::movePlayer() {
    //moves the player
    this->player->movePlayer();
    sf::FloatRect playerPos(this->player->playerSprite->baseSprite->getGlobalBounds());
    sf::Vector2f viewPos(this->gameView->getCenter());

    if (playerPos.left < viewPos.x - (gameData::screenWidth / 2)) {
        this->player->playerSprite->baseSprite->setPosition(viewPos.x - (gameData::screenWidth / 2), playerPos.top);
        playerPos.left = viewPos.x - (gameData::screenWidth / 2);
    }
    if (playerPos.top < 0) {
        this->player->playerSprite->baseSprite->setPosition(playerPos.left, 0);
        playerPos.top = 0;
    }
    if (playerPos.width + playerPos.left > viewPos.x + (gameData::screenWidth / 2)) {
        this->player->playerSprite->baseSprite->setPosition(viewPos.x + (gameData::screenWidth / 2) - playerPos.width, playerPos.top);
        playerPos.left = viewPos.x + (gameData::screenWidth / 2) - playerPos.width;
    }
    if (playerPos.top + playerPos.height > gameData::screenLength) {
        this->player->playerSprite->baseSprite->setPosition(playerPos.left, gameData::screenLength - playerPos.height);
        playerPos.top = gameData::screenLength - playerPos.height;
    }
}

void gameScreen::moveBullets() {
    //moves bullets
    for (int i = 0;i < this->bullets->size();i++) {
        if (this->bullets->at(i)->isActive) {
            this->bullets->at(i)->moveBullet();
        }
    }

    for (int i = 0;i < this->pBullets->size();i++) {
        if (this->pBullets->at(i)->isActive) {
            this->pBullets->at(i)->moveBullet();
        }
    }
}

void gameScreen::checkCollision() {
    //checks for collision between objects
    if (this->player->isInvuln() == false) {
        sf::Vector2f playerPos(this->player->playerSprite->baseSprite->getPosition());
        int pRadius = this->player->playerSprite->baseSprite->getLocalBounds().width / 4;
        playerPos.x = playerPos.x + pRadius;
        playerPos.y = playerPos.y + pRadius;

        this->isCollide = false;
        for (int i = 0;i < this->bullets->size();i++) {
            sf::Vector2f bulletPos(this->bullets->at(i)->bulletSprite->getPosition());
            int bRadius = this->bullets->at(i)->bulletSprite->getLocalBounds().width / 2;
            bulletPos.x = bulletPos.x + (this->bullets->at(i)->bulletSprite->getLocalBounds().width / 2);
            bulletPos.y = bulletPos.y + (this->bullets->at(i)->bulletSprite->getLocalBounds().height / 2);
            if (this->doesCollide(playerPos, pRadius, bulletPos, bRadius)) {
                this->playerCollide();
                this->isCollide = true;
            }
        }
    }

    for (int i = 0;i < this->enemies->size();i++) {
        if (this->enemies->at(i)->active) {
            sf::Vector2f enemyPos(this->enemies->at(i)->sprite->baseSprite->getPosition());
            int eRadius = this->enemies->at(i)->sprite->baseSprite->getLocalBounds().width / 2;
            enemyPos.x = enemyPos.x + eRadius;
            enemyPos.y = enemyPos.y + eRadius;

            for (int i2 = 0;i2 < this->pBullets->size();i2++) {
                sf::Vector2f bulletPos(this->pBullets->at(i2)->bulletSprite->getPosition());
                int bRadius = this->pBullets->at(i2)->bulletSprite->getLocalBounds().width / 2;
                bulletPos.x = bulletPos.x + (this->pBullets->at(i2)->bulletSprite->getLocalBounds().width / 2);
                bulletPos.y = bulletPos.y + (this->pBullets->at(i2)->bulletSprite->getLocalBounds().height / 2);
                if (this->doesCollide(enemyPos, eRadius, bulletPos, bRadius)) {
                    //enemy bullet collision stuff
                    std::cout << "YEOUCH!\n";
                    this->bulletCollideEnemy(i);
                }
            }
        }
    }
}

bool gameScreen::doesCollide(const sf::Vector2f& playerPos, int playerRadius, const sf::Vector2f& bulletPos, int bulletRadius) {
    float distance = sqrt(std::pow((playerPos.x - bulletPos.x), 2) + std::pow(playerPos.y - bulletPos.y, 2));
    if ( (playerRadius + bulletRadius) > distance ) {
        return true;
    } else {
        return false;
    }
}

void gameScreen::playerCollide() {
    //Called when player sprite intersects with a bullet sprite
    this->player->hit = true;
    gameData::lives--;
}

void gameScreen::bulletCollideEnemy(int index) {
    //Called when a players bullet intersects with an enemy. index of position of enemy to be deactivated
    this->enemies->at(index)->active = false;
    this->enemies->at(index)->defeated = true;
    sf::FloatRect enemyPos = enemies->at(index)->sprite->baseSprite->getGlobalBounds();
    events->push_back(new Event(animation, *assets::findAsset("Explosion_Sprite.png")->texture, 90, 17, enemyPos.left - enemyPos.width, enemyPos.top - enemyPos.height));
}

void gameScreen::generateBullets() {
    //checks if any enemies need to generate bullets, resets their bullet timers
    for (int i = 0;i < this->enemies->size();i++) {
        if (this->enemies->at(i)->active) {
            if (this->enemies->at(i)->readyToFire()) {
                this->bullets->push_back(this->enemies->at(i)->generateBullet(player->playerSprite->baseSprite->getPosition()));
                this->enemies->at(i)->resetBullet();
            } else {
                this->enemies->at(i)->incrementBullet();
            }
        }
    }
}

screenType gameScreen::screenManage(sf::RenderWindow* window) {
    //returns screenType the game should remain focused on. Game by default, and other screens when they have been properly flagged
    if (gameData::lives < 0) {
        gameData::lives = 4;
        window->setView(window->getDefaultView());
        return title;
    }
    else return game;
}