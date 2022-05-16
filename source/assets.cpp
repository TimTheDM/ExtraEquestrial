#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "headers\assets.h"

sf::Texture assets::titleBackground;
sf::Music assets::titleMusic;
sf::Texture assets::playSymbol;
sf::Texture assets::exitSymbol;
sf::Texture assets::playerSprite;
sf::Texture assets::cursor;
sf::Texture assets::testEnemy;
sf::Texture assets::stageBackground;
sf::Texture assets::testBullet;
sf::Texture assets::playerBullet;
sf::Texture assets::explosionSprite;
std::vector<assetContainer*>* assets::assetList;

bool assets::loadAssets() {
    namespace fs = std::experimental::filesystem;
    assetList = new std::vector<assetContainer*>;

    bool assetsLoaded = true;
    if (!assets::titleBackground.loadFromFile("sprites/Title_Background.png")) assetsLoaded = false;
    if (!assets::stageBackground.loadFromFile("sprites/Stage_Background.png")) assetsLoaded = false;
    if (!assets::playSymbol.loadFromFile("sprites/Play_Symbol.png")) assetsLoaded = false;
    if (!assets::exitSymbol.loadFromFile("sprites/Exit_Symbol.png")) assetsLoaded = false;
    if (!assets::explosionSprite.loadFromFile("sprites/Explosion_Sprite.png")) assetsLoaded = false;
    if (!assets::playerSprite.loadFromFile("sprites/Player_Sheet.png")) assetsLoaded = false;
    if (!assets::testBullet.loadFromFile("sprites/Test_Bullet.png")) assetsLoaded = false;
    if (!assets::playerBullet.loadFromFile("sprites/Player_Bullet.png")) assetsLoaded = false;
    if (!assets::cursor.loadFromFile("sprites/cursor.png")) assetsLoaded = false;
    if (!assets::testEnemy.loadFromFile("sprites/test_enemy.png")) assetsLoaded = false;
    if (!assets::titleMusic.openFromFile("music/Main_Menu.flac")) assetsLoaded = false;

    assetsLoaded = addAssets("sprites");
    assetsLoaded = addAssets("music");

    return assetsLoaded;
}

bool assets::addAssets(const std::string& assetPath) {
    for (const auto& entry : std::experimental::filesystem::directory_iterator(assetPath)) {
        std::string fileName;
        std::stringstream buffer;
        buffer << entry.path();
        fileName = buffer.str();
        assetList->push_back(new assetContainer(fileName));
    }

    return true;
}

assetContainer::assetContainer(const std::string& fileName) {
    this->fileName = new std::string(fileName);
    std::string extension = findExtension(fileName);

    if (extension == "png") {
        texture = new sf::Texture();
        texture->loadFromFile(fileName);
        isLoaded = true;
        type = image;
    } else if (extension == "flac") {
        song = new sf::Music;
        song->openFromFile(fileName);
        isLoaded = true;
        type = music;
    } else {
        isLoaded = false;
    }
}

std::string findExtension(const std::string& fileName) {
    return "";
}