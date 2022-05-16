#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <experimental/filesystem>

struct assetContainer {
    sf::Texture* texture;
    sf::Music* music;
    const std::string* fileName;
    bool isLoaded;
    assetContainer(const std::string&);
};

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
    static sf::Texture explosionSprite;
    static std::vector<assetContainer*>* assetList;
    static bool loadAssets();
};

#endif //ASSETS_H