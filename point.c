//
// Created by march on 3/22/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "point.h"

struct point{
    int px;
    int py;
};

struct point *create_point(int px, int py){
    struct point *mypoint = malloc(sizeof(struct point));
    mypoint->px = px;
    mypoint->py = py;
    return mypoint;
}