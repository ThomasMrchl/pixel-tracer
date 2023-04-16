//
// Created by march on 3/22/2023.
//

#include "point.h"
#ifndef PIXEL_TRACER_RECTANGLE_H
#define PIXEL_TRACER_RECTANGLE_H

typedef struct rectangle {
    Point *p1;
    int width;
    int length;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

#endif //PIXEL_TRACER_RECTANGLE_H
