//
// Created by march on 3/22/2023.
//

#ifndef PIXEL_TRACER_SQUARE_H
#define PIXEL_TRACER_SQUARE_H
#include "point.h"

typedef struct{
    Point *p1;
    int n;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

#endif //PIXEL_TRACER_SQUARE_H
