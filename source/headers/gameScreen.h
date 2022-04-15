#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "baseScreen.h"
#include "Enemy.h"

class gameScreen : public baseScreen {
    std::vector<Enemy>* enemies;
    sf::Sprite background;
    //std::vector<Bullet>* bullets;
    //Player* player; 
public:
    screenType run(sf::RenderWindow*);
    void draw(sf::RenderWindow*);
    void processInput(sf::RenderWindow*);
    void moveBackground();
    void moveEnemies();
    void moveBullets();
    void movePlayer();
    void checkCollision();
    gameScreen();
    ~gameScreen();
};

#endif //GAME_SCREEN_H