#include "headers\gameData.h"

const int INITIAL_WIDTH = 480;
const int INITIAL_LENGTH = 212;
const int STARTING_LIVES = 3;
const int STARTING_LEVEL = 1;

int gameData::screenWidth = 0;
int gameData::screenLength = 0;
int gameData::lives = 0;
int gameData::level = 0;
bool gameData::endProgram;

bool gameData::initializeData() {
    //initializes game data, returns whether or not initialization failed (cannot fail yet, will if file calls are involved)
    gameData::screenWidth = INITIAL_WIDTH;
    gameData::screenLength = INITIAL_LENGTH;
    gameData::lives = STARTING_LIVES;
    gameData::level = STARTING_LEVEL;
    gameData::endProgram = false;
    return true;
}