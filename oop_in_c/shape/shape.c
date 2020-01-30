#include <assert.h>
#include "shape.h"

static inline int Shape_area_(Shape const * const this);

void ShapeConstructor(Shape * const this, int _x, int _y) {
    static struct ShapeVtbl const vtbl = {
            &Shape_area_
    };

    this->vptr_ = &vtbl;
    this->x_ = _x;
    this->y_ = _y;
    return;
}

static inline int Shape_area_(Shape const * const this) {
    assert(0);
    return 0;
}

int Shape_GetX(Shape const * const this) { return this->x_; }
int Shape_GetY(Shape const * const this) { return this->y_; }