#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"
#include "headers\baseScreen.h"
#include "headers\titleScreen.h"

void runGame(sf::RenderWindow*);

int main()
{
    gameData::initializeData();
    sf::RenderWindow window(sf::VideoMode(gameData::screenWidth, gameData::screenLength), "Extra Equestrial");

    runGame(&window);

    return 0;
}

void runGame(sf::RenderWindow* window) {
    //runs game loop
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        window->display();
    }
}