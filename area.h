//
// Created by march on 5/7/2023.
//
#include <shapes.h>
#include "pixel.h"
#ifndef PIXEL_TRACER_AREA_H
#define PIXEL_TRACER_AREA_H

#define SHAPE_MAX 100
#define BOOL int

struct area {
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX];
    int nb_shape;
};
typedef struct area Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
int get_nb_pixel(Pixel** p1);
int in_list(Pixel** p1, int nb_pixels, int x, int y);
void draw_area(Area* area);
void print_area(Area* area);

#endif //PIXEL_TRACER_AREA_H

