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

    for (int i=0; i<nb_pixels; i++){
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

void test_pixel_line() {
    // Create a line from (1, 1) to (5, 5)
    Line* line = create_line(1, 1, 5, 5);

    // Call the pixel_line function
    Pixel* pixels;
    int num_pixels;
    pixel_line(line, &pixels, &num_pixels);

    // Check that the correct number of pixels were generated
    assert(num_pixels == 5);

    // Check that the correct pixels were generated
    assert(pixels[0].px == 1 && pixels[0].py == 1);
    assert(pixels[1].px == 2 && pixels[1].py == 2);
    assert(pixels[2].px == 3 && pixels[2].py == 3);
    assert(pixels[3].px == 4 && pixels[3].py == 4);
    assert(pixels[4].px == 5 && pixels[4].py == 5);
}