#ifndef GAME_DATA_H
#define GAME_DATA_H

class gameData {
    //container that stores users settings, and other screen independent data, such as level the user is on, and remaining lives
public:
    static int screenWidth;
    static int screenLength;
    static int lives;
    static int level;
    static bool endProgram;

    //initializes the data, currently from constants defined in gameData.cpp
    static bool initializeData();
};

#endif //gameData.h