#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\assets.h"
#include "headers\baseScreen.h"
#include "headers\titleScreen.h"
#include "headers\gameScreen.h"
#include "headers\cutsceneScreen.h"

void runGame(sf::RenderWindow*);
baseScreen* switchScreen(baseScreen*, screenType);

int main()
{
    gameData::initializeData();
    assets::loadAssets();
    sf::RenderWindow window(sf::VideoMode(gameData::screenWidth, gameData::screenLength), "Extra Equestrial");
    window.setSize(sf::Vector2u(gameData::screenWidth * 3, gameData::screenLength * 3));
    window.setFramerateLimit(120);

    runGame(&window);

    return 0;
}

void runGame(sf::RenderWindow* window) {
    //runs game loop
    baseScreen* currentScreen = new TitleScreen();
    screenType currentScreenType = title;
    screenType screenToSwitch;

    while (window->isOpen())
    {
        if (gameData::endProgram) window->close();

        currentScreen->draw(window);
        screenToSwitch = currentScreen->run(window);

        if (screenToSwitch != currentScreenType) {
            currentScreen = switchScreen(currentScreen, screenToSwitch);
            currentScreenType = screenToSwitch;
        }
    }
}

baseScreen* switchScreen(baseScreen* currentScreen,screenType screenToSwitch) {
    //constructs a new screen object, deletes the old one currentScreen is pointing to. Returns reference to new screen object
    std::cout << "Guh?";
    delete currentScreen;
    if (screenToSwitch == cutscene) return new cutsceneScreen();
    else if (screenToSwitch == game) return new gameScreen();
    else return new TitleScreen();
}
