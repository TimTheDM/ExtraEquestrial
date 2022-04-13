#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\assets.h"

sf::Texture assets::titleBackground;
sf::Music assets::titleMusic;
sf::Texture assets::playSymbol;
sf::Texture assets::exitSymbol;
sf::Texture assets::cursor;

bool assets::loadAssets() {
    bool assetsLoaded = true;
    if (!assets::titleBackground.loadFromFile("sprites/Title_Background.png")) assetsLoaded = false;
    if (!assets::playSymbol.loadFromFile("sprites/Play_Symbol.png")) assetsLoaded = false;
    if (!assets::exitSymbol.loadFromFile("sprites/Exit_Symbol.png")) assetsLoaded = false;
    if (!assets::cursor.loadFromFile("sprites/cursor.png")) assetsLoaded = false;
    if (!assets::titleMusic.openFromFile("music/Main_Menu.flac")) assetsLoaded = false;
    return assetsLoaded;
}