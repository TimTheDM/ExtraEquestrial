#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "baseScreen.h"
#include "assets.h"
#include "Enemy.h"
#include "player.h"
#include "bullet.h"
#include "event.h"

class gameScreen : public baseScreen {
    std::vector<Enemy*>* enemies;
    std::vector<Event*>* events;
    sf::Sprite* background;
    sf::View* gameView;
    std::vector<Bullet*>* bullets;
    std::vector<Bullet*>* pBullets;
    Player* player;
    bool isCollide;
    bool isScroll;
    void processInput(sf::RenderWindow*);
    void moveView(sf::RenderWindow*);
    screenType screenManage(sf::RenderWindow*);
    void manageEvents();
    void managePlayer();
    void manageActive();
    void moveBackground();
    void moveEnemies();
    void moveBullets();
    void movePlayer();
    void checkCollision();
    void playerCollide();
    void bulletCollideEnemy(int);
    void generateBullets();
    bool doesCollide(const sf::Vector2f&, int, const sf::Vector2f&, int);
public:
    screenType run(sf::RenderWindow*);
    void draw(sf::RenderWindow*);
    gameScreen();
    ~gameScreen();
};

#endif //GAME_SCREEN_H