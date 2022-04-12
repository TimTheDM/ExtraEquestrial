#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\titleScreen.h"
#include "headers\gameScreen.h"
#include "headers\cutsceneScreen.h"

void runGame(sf::RenderWindow*);
baseScreen* switchScreen(baseScreen*, screenType);

int main()
{
    gameData::initializeData();
    sf::RenderWindow window(sf::VideoMode(gameData::screenWidth, gameData::screenLength), "Extra Equestrial");

    runGame(&window);

    return 0;
}

void runGame(sf::RenderWindow* window) {
    //runs game loop
    baseScreen* currentScreen = new titleScreen();
    screenType currentScreenType = title;
    screenType screenToSwitch;

    while (window->isOpen())
    {
        screenToSwitch = currentScreen->run();

        if (screenToSwitch != currentScreenType) {
            currentScreen = switchScreen(currentScreen, screenToSwitch);
            currentScreenType = screenToSwitch;
        }

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}

baseScreen* switchScreen(baseScreen* currentScreen,screenType screenToSwitch) {
    //constructs a new screen object, deletes the old one currentScreen is pointing to. Returns reference to new screen object
    if (screenToSwitch = title) return new titleScreen();
    else return new titleScreen();
}