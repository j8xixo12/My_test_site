#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

typedef struct {
    Shape parent;

    int width_;
    int height_;
}Rectangle;

void RectangleConstructor(Rectangle * const this, int _x, int _y, int _width, int _height);

#endif // RECTANGLE_H_