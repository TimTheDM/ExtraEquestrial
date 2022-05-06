#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct assets {
    //container storing textures and music for use in the screens
    static sf::Texture titleBackground;
    static sf::Texture stageBackground;
    static sf::Texture playSymbol;
    static sf::Texture playerSprite;
    static sf::Texture testBullet;
    static sf::Texture playerBullet;
    static sf::Texture exitSymbol;
    static sf::Texture cursor;
    static sf::Texture testEnemy;
    static sf::Music titleMusic;
    static bool loadAssets();
};

#endif //ASSETS_H