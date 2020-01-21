#ifndef SHAPE_H_
#define SHAPE_H_

struct ShapeVtbl;

typedef struct {
    struct ShapeVtbl const *vptr_;
    int x_;
    int y_;
}Shape;

struct ShapeVtbl {
    int (*Area) (Shape const * const);
};

void ShapeConstructor(Shape * const this, int _x, int _y);
int Shape_GetX(Shape const * const this);
int Shape_GetY(Shape const * const this);

static inline int Shape_area(Shape const * const this) {
    return (*this->vptr_->Area)(this);
}

#endif // SHAPE_H_