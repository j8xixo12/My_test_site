#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "shape.h"

typedef struct {
    Shape parent;

    int bottom_;
    int height_;
}Triangle;

void TriangleConstructor(Triangle * const this, int _x, int _y, int _bottom, int _height);


#endif // TRIANGLE_H_