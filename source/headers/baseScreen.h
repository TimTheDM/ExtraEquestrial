#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

enum screenType {title, game, cutscene};

class baseScreen {
    //base abstract class for a screen of the game, contains only undefined virtual members
    virtual screenType run() = 0;
};

#endif //BASE_SCREEN_H