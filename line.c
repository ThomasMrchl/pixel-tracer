//
// Created by march on 3/22/2023.
//

#include "line.h"
#include <stdlib.h>
#include <stdio.h>


Line *create_line(int x1, int y1, int x2, int y2){
    Line *l1 = (Line *) malloc(sizeof(Line));
    l1->p1 = create_point(x1, y1);
    l1->p2 = create_point(x1, y2);
    return l1;
}

void print_line(Line * l){
    printf("LINE : %d %d %d %d", l->p1->pos_x, l->p1->pos_y, l->p2->pos_x, l->p2->pos_y);
}

void delete_line(Line * line){
    free(line);
}