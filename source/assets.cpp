#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

bool assets::loadAssets() {
    bool assetsLoaded = true;
    if (!assets::titleBackground.loadFromFile("sprites/Title_Background.png")) assetsLoaded = false;
    if (!assets::stageBackground.loadFromFile("sprites/Stage_Background.png")) assetsLoaded = false;
    if (!assets::playSymbol.loadFromFile("sprites/Play_Symbol.png")) assetsLoaded = false;
    if (!assets::exitSymbol.loadFromFile("sprites/Exit_Symbol.png")) assetsLoaded = false;
    if (!assets::playerSprite.loadFromFile("sprites/Player_Sheet.png")) assetsLoaded = false;
    if (!assets::testBullet.loadFromFile("sprites/Test_Bullet.png")) assetsLoaded = false;
    if (!assets::playerBullet.loadFromFile("sprites/Player_Bullet.png")) assetsLoaded = false;
    if (!assets::cursor.loadFromFile("sprites/cursor.png")) assetsLoaded = false;
    if (!assets::testEnemy.loadFromFile("sprites/test_enemy.png")) assetsLoaded = false;
    if (!assets::titleMusic.openFromFile("music/Main_Menu.flac")) assetsLoaded = false;
    return assetsLoaded;
}