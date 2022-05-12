#include <SFML/Graphics.hpp>
#include "headers\spriteSheet.h"
#include "headers\event.h"

Event::Event(eventType type, int time, int offset, const sf::Texture& texture) {
    this->time = time;
    timer = 0;
    this->type = type;

    if (type == animation) {
        animationSheet = new SpriteSheet(texture, offset, time / offset);
    }
}

Event::~Event() {
    if (type == animation) {
        delete animationSheet;
    }
}