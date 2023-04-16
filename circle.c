//
// Created by march on 3/22/2023.
//

#include "circle.h"
#include <stdio.h>
#include <stdlib.h>

Circle *create_circle(Point * center, int radius){
    Circle *c1 = (Circle*)malloc(sizeof(Circle));
    c1->radius=radius;
    c1->p1=center;
    return c1;
}

void delete_circle(Circle * circle){
    free(circle);
}

void print_circle(Circle * circle){
    printf("CIRCLE : %d %d  radius : %d", circle->p1->pos_x, circle->p1->pos_y, circle->radius);
}