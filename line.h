//
// Created by march on 3/22/2023.
//

#ifndef PIXEL_TRACER_LINE_H
#define PIXEL_TRACER_LINE_H
#include "line.h"
#include "point.h"

typedef struct {
    Point *p1;
    Point *p2;
} Line;

Line *create_line(int x1, int y1, int x2, int y2);
void delete_line(Line * line);
void print_line(Line * l);

#endif //PIXEL_TRACER_LINE_H
