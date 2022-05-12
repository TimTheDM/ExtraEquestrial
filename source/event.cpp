#include <SFML/Graphics.hpp>
#include "headers\spriteSheet.h"
#include "headers\event.h"

Event::Event(eventType type, const sf::Texture& texture, int time, int offset, float xpos, float ypos) {
    this->time = time;
    timer = 0;
    this->type = type;

    if (type == animation) {
        animationSheet = new SpriteSheet(texture, offset, time / offset);
        animationSheet->baseSprite->setPosition(xpos, ypos);
    }
}

Event::~Event() {
    if (type == animation) {
        delete animationSheet;
    }
}

bool Event::isActive() {
    if (timer == time) return false;
    else return true;
}

eventType Event::getType() {
    return type;
}

void Event::tick() {
    if (timer != time) {
        timer++;
        animationSheet->nextPos();
    }
}

void Event::disable() {
    timer = time;
}