//
// Created by march on 5/7/2023.
//

#include "area.h"
#include "stdlib.h"

Area* create_area(unsigned int width, unsigned int height){
    Area *a1 = (Area*)malloc(sizeof(Area));
    a1->height=height;
    a1->width=width;
    a1->nb_shape=0;
    return a1;
}

void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape] = shape;
    area->nb_shape++;
}

void clear_area(Area* area){
    int **matrix = malloc(area->height * sizeof(int *));
    for (int i = 0; i < area->height; i++) {
        matrix[i] = calloc(area->width, sizeof(int));
    }
    area->mat = matrix;
}

void erase_area(Area* area){
    for (int i = 0; i < area->nb_shape; i++) {
        free(area->mat[i]);
    }
    free(area->mat);

    for (int j =0; j < area->height; j++){
        free(area->mat[j]);
    }
    free(area->mat);
}

void delete_area(Area* area){
    erase_area(area);
    free(area);
}

/*
void draw_area(Area* area){
    for (int i=0; i<area->nb_shape; i++){
        //create_shape_to_pixel(area->shapes[i]);
        //continuer plus tard
    }
}

void print_area(Area* area){
    //utilisée plus tard
}
*/
