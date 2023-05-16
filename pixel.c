//
// Created by march on 5/7/2023.
//

#include <assert.h>
#include "pixel.h"
#include "stdlib.h"
#include "stdio.h"

Pixel* create_pixel(int px, int py){
    Pixel *p1 = (Pixel*)malloc(sizeof (Pixel));
    p1->px = px;
    p1->py = py;
    return p1;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Shape *shape, Pixel ***pixel_tab, int *nb_pixels) {
    Point* pt = (Point*) shape->ptrShape;
    *pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    *pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}


int min(int v1, int v2){
    if (v1<v2){
        return v1;
    } else {
        return v2;
    }
}

int max(int v1, int v2){
    if (v1>v2){
        return v1;
    } else {
        return v2;
    }
}

void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels){
    int x1 = line->p1->pos_x;
    int y1 = line->p1->pos_y;
    int x2 = line->p2->pos_x;
    int y2 = line->p2->pos_y;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int dmin = min(dx, abs(dy));
    int dmax = max(dx, abs(dy));

    int nb_segs = dmin + 1;

    int taille_de_base = (dmax + 1)/(dmin +1 );

    int segments[nb_segs];

    for (int i = 0; i < nb_segs; i++) {
        segments[i] = taille_de_base;
    }

    int restants = (dmax + 1) % (dmin +1);

    int nombre_total_pixel = nb_segs * taille_de_base + restants;

    *nb_pixels = nombre_total_pixel;
    printf("%d\n", *nb_pixels);

    *pixel = (Pixel **) malloc(sizeof(Pixel **) * *nb_pixels);

    int *cumuls = (int*)malloc(nb_segs*sizeof(int));

    cumuls[0]=0;
    for (int i = 1; i < nb_segs ; i++){
        cumuls[i] = ((i+1)*restants)%(dmin+1) < ((i*restants)%(dmin+1));
        segments[i] = segments[i] + cumuls[i];
    }

    if (dy < 0){
        if (dx > abs(dy)){
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                y1--;
            }
        } else {
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    y1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                x1--;
            }
        }
    } else {
        if (dx > dy){
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                y1++;
            }
        } else {
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel *p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j<segments[i]; j++) {
                    y1++;
                    Pixel *p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                x1++;
            }
        }
    }

    /*
    printf(" pixels :\n");
    for (int i = 0; i < *nb_pixels; i++) {
        printf(" %d %d \n", (*pixel)[i]->px, (*pixel)[i]->py);
    }
    */

}

Pixel** create_shape_to_pixel(Shape* shape, int* nb_pixels){
    if (shape->shape_type==POINT){
        Pixel **pixels = NULL;
        pixel_point(shape->ptrShape, &pixels, nb_pixels);
        return pixels;

    } else if (shape->shape_type==LINE){
        Pixel **pixels = NULL;
        pixel_line(shape->ptrShape, &pixels, nb_pixels);
        return pixels;
    }
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    //il faut free chaque pixel de la variable pixel
    free(pixel);
}
