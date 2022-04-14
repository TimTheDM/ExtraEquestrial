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

void Path::incrementPath() {
    if (this->mutation != 0.0) {
        this->angle += this->mutation;
        this->x_offset = cos(this->angle);
        this->y_offset = -sin(this->angle);
    }
    this->timer++;
}

float Path::retrieve_x_offset() {
    return this->x_offset;
}

float Path::retrieve_y_offset() {
    return this->y_offset;
}

bool Path::isDone() {
    return (this->timer >= this->time);
}