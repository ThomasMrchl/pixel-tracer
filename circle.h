//
// Created by march on 3/22/2023.
//

#include "point.h"
#ifndef PIXEL_TRACER_CIRCLE_H
#define PIXEL_TRACER_CIRCLE_H

typedef struct circle {
    int radius;
    Point *p1;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

#endif //PIXEL_TRACER_CIRCLE_H
