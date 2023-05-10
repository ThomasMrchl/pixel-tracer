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

void pixel_point(Point *point, Pixel **pixel, int *nb_pixels) {
    printf("2");
    pixel = (Pixel**) malloc (sizeof (Pixel*));
    printf("2");
    pixel[0] = create_pixel(point->pos_x, point->pos_y);
    printf("2");
    *nb_pixels = 1;
    printf("2");
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

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
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

    int *cumuls = (int*)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;
    for (int i = 1; i < nb_segs ; i++){
        cumuls[i] = ((i+1)*restants)%(dmin+1) < ((i*restants)%(dmin+1));
        segments[i] = segments[i] + cumuls[i];
    }

    if (dy < 0){
        if (dx > abs(dy)){
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            pixel[*nb_pixels] = p1;
            (*nb_pixels)++;
            for (int i=0; i<nb_segs-1;i++){
                for (int j=0; j<nb_segs; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    pixel[*nb_pixels] = p1;
                    (*nb_pixels)++;
                }
                y1--;
            }
        } else {
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            pixel[*nb_pixels] = p1;
            (*nb_pixels)++;
            for (int i=0; i<nb_segs-1;i++){
                for (int j=0; j<nb_segs; j++){
                    y1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    pixel[*nb_pixels] = p1;
                    (*nb_pixels)++;
                }
                x1--;
            }
        }
    } else {
        if (dx > dy){
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            pixel[*nb_pixels] = p1;
            (*nb_pixels)++;
            for (int i=0; i<nb_segs-1;i++){
                for (int j=0; j<nb_segs; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    pixel[*nb_pixels] = p1;
                    (*nb_pixels)++;
                }
                y1++;
            }
        } else {
            segments[0] = segments[0] - 1;
            Pixel *p1 = create_pixel(x1, y1);
            pixel[*nb_pixels] = p1;
            (*nb_pixels)++;
            for (int i = 0; i < nb_segs - 1; i++) {
                for (int j = 0; j < nb_segs; j++) {
                    y1++;
                    Pixel *p1 = create_pixel(x1, y1);
                    pixel[*nb_pixels] = p1;
                    (*nb_pixels)++;
                }
                x1++;
            }
        }
    }

    for (int i=0; i<nb_segs; i++){
        printf("%d %d   ", pixel[i]->px, pixel[i]->py );
    }
}


/*
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
    int x1 = line->p1->pos_x;
    int y1 = line->p1->pos_y;
    int x2 = line->p2->pos_x;
    int y2 = line->p2->pos_y;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int incx = (x2 > x1) ? 1 : -1;
    int incy = (y2 > y1) ? 1 : -1;

    int x = x1;
    int y = y1;

    if (dx >= dy) {
        int d = 2*dy - dx;
        while (x != x2) {
            Pixel* p = create_pixel(x, y);
            *nb_pixels += 1;
            pixel = realloc(pixel, (*nb_pixels) * sizeof(Pixel*));
            pixel[*nb_pixels-1] = p;

            if (d > 0) {
                y += incy;
                d -= 2*dx;
            }
            d += 2*dy;
            x += incx;
        }
    } else {
        int d = 2*dx - dy;
        while (y != y2) {
            Pixel* p = create_pixel(x, y);
            *nb_pixels += 1;
            pixel = realloc(pixel, (*nb_pixels) * sizeof(Pixel*));
            pixel[*nb_pixels-1] = p;

            if (d > 0) {
                x += incx;
                d -= 2*dy;
            }
            d += 2*dx;
            y += incy;
        }
    }
    Pixel* p = create_pixel(x, y);
    *nb_pixels += 1;
    pixel = realloc(pixel, (*nb_pixels) * sizeof(Pixel*));
    pixel[*nb_pixels-1] = p;
}
*/


Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    if (shape->shape_type==POINT){
        Pixel **pixels = NULL;
        printf("1");
        pixel_point(shape->ptrShape, pixels, nb_pixels);
        printf("1");
        print_pixels(pixels, *nb_pixels);
        printf("1");
        return pixels;
    } else if (shape->shape_type==LINE){
        Pixel **pixels = NULL;
        pixel_line(shape->ptrShape, pixels, nb_pixels);
        print_pixels(pixels, *nb_pixels);
        return pixels;
    }
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    //il faut free chaque pixel de la variable pixel
    free(pixel);
}

void print_pixels(Pixel** pixels, int nb_pixels){
    printf("entree");
    for (int i = 0; i < nb_pixels; i++){
        printf("\n");
        printf(" %d %d", pixels[i]->px, pixels[i]->py);
    }
}