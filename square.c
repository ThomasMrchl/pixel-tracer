//
// Created by march on 3/22/2023.
//

#include "square.h"
#include <stdio.h>
#include <stdlib.h>

Square *create_square(Point * point, int length){
    Square *s1 = (Square*)malloc(sizeof (Square));
    s1->p1 = point;
    s1->n = length;
    return s1;
}

void delete_square(Square * square){
    free(square);
}

void print_square(Square * square){
    printf(" SQUARE : Size : %d\n", square->n);
    print_point(square->p1);
}
