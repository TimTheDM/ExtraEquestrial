#ifndef PATH_H
#define PATH_H

const float PI = 3.141592;

class path {
    //stores data for path an enemy takes by angle, time spent on path, and mutation of that angle per game tick
    float x_offset;
    float y_offset;
    float angle;
    float mutation;
    int timer;
    int time;
public: 
    path(int, float, float);
};

#endif //PATH_H