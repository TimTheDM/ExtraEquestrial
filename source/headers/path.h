#ifndef PATH_H
#define PATH_H

#include <math.h>

const float PI = 3.141592;

class Path {
    //stores data for path an enemy takes by angle, time spent on path, and mutation of that angle per game tick
    float x_offset;
    float y_offset;
    float angle;
    float mutation;
    int timer;
    int time;
public: 
    Path(int, float, float);
    void incrementPath();
    float retrieve_x_offset();
    float retrieve_y_offset();
    bool isDone();
};

#endif //PATH_H