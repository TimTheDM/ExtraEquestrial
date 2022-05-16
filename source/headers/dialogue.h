#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <SFML/Graphics.hpp>
#include <vector>

enum speaker{sheriff, deputy};

class Dialogue
{
    std::string script;
    float triggerPoint;
    speaker dialogueSpeaker;
public:
    Dialogue(std::string script, float triggerPoint, speaker dialogueSpeaker);
    std::string getScript();
    float getTrigger();
    speaker getSpeaker();
};
#endif //DIALOGUE_H
