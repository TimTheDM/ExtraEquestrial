#ifndef GAME_DATA_H
#define GAME_DATA_H

class gameData {
    //container that stores users settings, and other screen independent data, such as level the user is on, and remaining lives
    static int screenWidth;
    static int screenLength;
    static int lives;

    //initializes the data, currently from constants defined in gameData.cpp
    bool initializeData;
};

#endif //gameData.h