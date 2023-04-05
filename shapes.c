//
// Created by march on 3/29/2023.
//

#include "shapes.h"
#include <stdio.h>
#include <stdlib.h>

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1;
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Line *l = create_line(px1, py1, px2, py2);
    shp -> ptrShape = l;
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p1 = create_point(px, py);
    Square *s1 = create_square(p1, length);
    shp -> ptrShape = s1;
    return shp;
}


void delete_shape(Shape * shape){
    free(shape);
}

void print_shape(Shape * shape){
    printf("%d ", shape->id);
   if (shape->shape_type == POINT){
       print_point(shape->ptrShape);
   } else if (shape->shape_type == LINE){
       print_line(shape->ptrShape);
   } else if (shape->shape_type == SQUARE){
       print_square(shape->ptrShape);
   }
}