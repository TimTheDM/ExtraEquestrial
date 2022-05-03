#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "baseScreen.h"
#include "assets.h"
#include "Enemy.h"
#include "player.h"
#include "bullet.h"

class gameScreen : public baseScreen {
    std::vector<Enemy*>* enemies;
    sf::Sprite* background;
    sf::View* gameView;
    std::vector<Bullet*>* bullets;
    Player* player;
    bool isCollide;
    void processInput(sf::RenderWindow*);
    void moveView(sf::RenderWindow*);
    void moveBackground();
    void moveEnemies();
    void moveBullets();
    void movePlayer();
    void checkCollision();
    void playerCollide();
    void generateBullets();
    bool doesCollide(const sf::Vector2f&, int, const sf::Vector2f&, int);
public:
    screenType run(sf::RenderWindow*);
    void draw(sf::RenderWindow*);
    gameScreen();
    ~gameScreen();
};

#endif //GAME_SCREEN_H