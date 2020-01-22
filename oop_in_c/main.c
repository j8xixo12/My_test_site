#include <stdio.h>
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"

int main(int argc, char *argv[]) {
    Rectangle R1, R2;
    Triangle T1, T2;

    RectangleConstructor(&R1, 0, 0, 10, 20);
    RectangleConstructor(&R2, 0, 0, 10, 25);

    TriangleConstructor(&T1, 0, 0, 10, 20);
    TriangleConstructor(&T2, 0, 0, 10, 25);

    Shape *collect[] = {
        &R1.parent,
        &R2.parent,
        &T1.parent,
        &T2.parent
    };
    for (int i = 0; i < (sizeof(collect) / sizeof(collect[0])); ++i) {
        printf("Area : %i\n", Shape_area(collect[i]));
    }
    return 0;
}