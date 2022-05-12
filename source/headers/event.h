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
    SpriteSheet* animation;
    bool isActive();
    void tick();
    void disable();
    Event(eventType type, int time);
    ~Event();
}

#endif //EVENT_H