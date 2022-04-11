#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "headers\gameData.h"

int main()
{
    gameData::initializeData();
    sf::RenderWindow window(sf::VideoMode(gameData::screenWidth, gameData::screenLength), "Extra Equestrial");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}