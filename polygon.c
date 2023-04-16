//
// Created by march on 3/22/2023.
//

#include "polygon.h"
#include <stdio.h>
#include <stdlib.h>

Polygon *create_polygon(int n){
    Polygon *p1 = (Polygon*)malloc(sizeof(Polygon));
    p1->n=n;
    p1->points=(Point**)malloc(sizeof(Point*)*n);
    return p1;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
}

void print_polygon(Polygon * polygon){
    printf("POLYGON : %d Points :", polygon->n);
    for (int i=0;i<polygon->n;i++){
        printf("POINT %d : %d %d", i+1, polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }
}