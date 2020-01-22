#include "rectangle.h"

int Rectangle_Area_(Shape const * const this);

void RectangleConstructor(Rectangle * const this, int _x, int _y, int _width, int _height) {
    static struct ShapeVtbl const vtbl = {
        &Rectangle_Area_
    };

    ShapeConstructor(&(this->parent), _x, _y);

    this->parent.vptr_ = &vtbl;
    this->width_ = _width;
    this->height_ = _height;
}

int Rectangle_Area_(Shape const * const this) {
    return ((Rectangle const *)this)->width_ * ((Rectangle const *)this)->height_;
}