//
// Created by march on 3/22/2023.
//

#include "polygon.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

Polygon *create_polygon(int n){
    Polygon *p1 = (Polygon *) malloc(sizeof(Polygon));
    p1->points = (Point**)malloc(sizeof (Point)*n);
    p1->n = n;
    int i=0;
    while (i<n){
        p1->points[i] = create_point(1, 1);
        i++;
    }
    return p1;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
}

void print_polygon(Polygon * polygon){
    printf("POLYGON : %d points \n", polygon->n);
    int i;
    for (i = 0; i < polygon->n; i++){
        printf("POINT %d COORD : %d %d \n", i+1, polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }
}