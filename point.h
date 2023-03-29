#ifndef POINT_H
#define POINT_H

typedef struct {
    int pos_x;
    int pos_y;
} Point;

Point *create_point(int px, int py);
void delete_point(Point *);
void print_point(Point *);

#endif