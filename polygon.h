//
// Created by march on 3/22/2023.
//

#include "point.h"
#ifndef PIXEL_TRACER_POLYGON_H
#define PIXEL_TRACER_POLYGON_H
//LE CUL
typedef struct polygon {
    int n;
    Point ** points;
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif //PIXEL_TRACER_POLYGON_H
