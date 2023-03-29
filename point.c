//
// Created by march on 3/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "point.h"

Point *create_point(int px, int py) {
    Point p1;
    p1.pos_x = px;
    p1.pos_y = py;
    return &p1;
}

void delete_point(Point * point){

}

void print_point(Point * p){
    printf("The coordiantes of your point are : %d %d", p->pos_x, p->pos_y);
}