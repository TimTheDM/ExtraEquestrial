#ifndef PATH_H
#define PATH_H

const float PI = 3.141592;

class path {
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