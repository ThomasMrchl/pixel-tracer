//
// Created by march on 5/7/2023.
//

#include "area.h"
#include "stdlib.h"
#include "point.h"
#include "stdio.h"

Area* create_area(unsigned int width, unsigned int height){
    Area *a1 = (Area*)malloc(sizeof(Area));
    a1->height=height;
    a1->width=width;
    a1->nb_shape=0;
    a1->mat[width][height];
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

int in_list(Pixel** p1, int nb_pixels, int x, int y){
    for (int n=0; n<nb_pixels ; n++){
        if ((p1[n]->px==x)&&(p1[n]->py==y)){
            return 1;
        }
    }
    return 0;
}

void draw_area(Area* area){
    for (int i=0; i < area->nb_shape; i++){
        if (area->shapes[i]->shape_type==POINT){
            int *nb_pixels = NULL;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], nb_pixels);
        } else if (area->shapes[i]->shape_type==LINE){
            int* nb_pixels = NULL;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], nb_pixels);
            printf("%d", *nb_pixels);
            for (int j=0; j<area->width; j++){
                for (int k=0; k<area->height; k++){
                    if (in_list(p1, *nb_pixels, j, k)==1){
                        area->mat[j][k] = 1;
                    } else {
                        area->mat[j][k] = 0;
                    }
                }
            }
        }
    }
}

void print_area(Area* area){
    //utilisée plus tard
}

