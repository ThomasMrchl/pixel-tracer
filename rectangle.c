//
// Created by march on 3/22/2023.
//

#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>

Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *r1 = (Rectangle*)malloc(sizeof(Rectangle));
    r1->width = width;
    r1->length = height;
    r1->p1 = point;
    return r1;
}

void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}

void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE : %d %d width : %d heigth : %d", rectangle->p1->pos_x, rectangle->p1->pos_y, rectangle->width, rectangle->length);
}