#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\assets.h"

sf::Texture assets::titleBackground;
sf::Music assets::titleMusic;

bool assets::loadAssets() {
    bool assetsLoaded = true;
    if (!assets::titleBackground.loadFromFile("sprites/Title_Background.png")) assetsLoaded = false;
    if (!assets::titleMusic.openFromFile("music/Main_Menu.flac")) assetsLoaded = false;
    return assetsLoaded;
}