#include "triangle.h"

int Triangle_Area(Shape const * const this);

void TriangleConstructor(Triangle * const this, int _x, int _y, int _bottom, int _height) {
    static struct ShapeVtbl vtbl = {
        &Triangle_Area
    };
    ShapeConstructor(&(this->parent), _x, _y);
    this->parent.vptr_ = &vtbl;
    this->bottom_ = _bottom;
    this->height_ = _height;
    return;
}

int Triangle_Area(Shape const * const this) {
    return 0.5 * (((Triangle const *) this)->bottom_* ((Triangle const *) this)->height_);
}