//
// Created by march on 5/7/2023.
//

#include "pixel.h"
#include "stdlib.h"

Pixel* create_pixel(int px, int py){
    Pixel *p1 = (Pixel*)malloc(sizeof (Pixel));
    p1->px = px;
    p1->py = py;
    return p1;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels){
    Point* pt = (Point*) shape->ptrShape;
    Pixel** pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
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

