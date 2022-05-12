#ifndef EVENT_H
#define EVENT_H

#include <SFML/Graphics.hpp>
#include "spriteSheet.h"

enum eventType {animation, sfx};

class Event {
    eventType type;
    int time;
    int timer;
public:
    SpriteSheet* animationSheet;
    bool isActive();
    void tick();
    void disable();
    Event(eventType type, int time, int offset, const sf::Texture& texture);
    ~Event();
};

#endif //EVENT_H