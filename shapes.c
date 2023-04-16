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

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p1 = create_point(px, py);
    Rectangle *r1= create_rectangle(p1, width, height);
    shp->ptrShape=r1;
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p1 = create_point(px, py);
    Circle *c1 = create_circle(p1, radius);
    shp->ptrShape = c1;
    return shp;
}

Shape *create_polygon_shape(int lst[], int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly = create_polygon(n);
    shp->ptrShape = poly;
    return shp;
}

void print_shape(Shape * shape){
    printf("%d ", shape->id);
   if (shape->shape_type == POINT){
       print_point(shape->ptrShape);
   } else if (shape->shape_type == LINE){
       print_line(shape->ptrShape);
   } else if (shape->shape_type == SQUARE){
       print_square(shape->ptrShape);
   } else if (shape->shape_type == CIRCLE){
       print_circle(shape->ptrShape);
   } else if (shape->shape_type == RECTANGLE){
       print_rectangle(shape->ptrShape);
   } else if (shape->shape_type == POLYGON){
       print_polygon(shape->ptrShape);
   }
}