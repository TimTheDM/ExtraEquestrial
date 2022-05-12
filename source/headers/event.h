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
    eventType getType();
    void tick();
    void disable();
    Event(eventType type, const sf::Texture& texture, int time, int offset, float xpos, float ypos);
    ~Event();
};

#endif //EVENT_H