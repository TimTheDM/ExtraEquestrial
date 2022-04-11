#include "headers\gameData.h"

const int INITIAL_WIDTH = 750;
const int INITIAL_LENGTH = 500;
const int STARTING_LIVES = 3;

int gameData::screenWidth = 0;
int gameData::screenLength = 0;
int gameData::lives = 0;

bool gameData::initializeData() {
    //initializes game data, returns whether or not initialization failed (cannot fail yet, will if file calls are involved)
    gameData::screenWidth = INITIAL_WIDTH;
    gameData::screenLength = INITIAL_LENGTH;
    gameData::lives = STARTING_LIVES;
    return true;
}