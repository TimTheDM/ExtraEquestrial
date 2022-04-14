#include "headers\Path.h"
#include "math.h"

Path::Path(int time, float angle, float mutation) {
    if (time < 1) this->time = 1;
    else this->time = time;
    this->timer = 0;
    this->mutation = mutation;
    this->angle = angle;
    this->x_offset = cos(angle);
    this->y_offset = -sin(angle);
}