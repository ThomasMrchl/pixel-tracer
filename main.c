#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "polygon.h"
#include "shapes.h"
#include "pixel.h"
#include "area.h"
#include <stdbool.h>

int main() {
    char direction;
    char action;
    bool selected = true;


    Area *a1 = create_area(10, 30);
    while (selected == true) {

        printf("\n");
        printf("Please select an action:\n");
        printf("   A- Add a shape:\n");
        printf("   B- Display the list of shapes:\n");
        printf("   C - Delete a shape:\n");
        printf("   D- Drawing the shapes:\n");
        printf("   E- Help:\n");
        printf("   F- Exit:\n");
        printf("----------Your action----------\n");
        scanf(" %c", &direction);

        while (((direction < 65) || (direction > 70))) {

            printf("\n");
            printf("Please select an action:\n");
            printf("   A- Add a shape:\n");
            printf("   B- Display the list of shapes:\n");
            printf("   C - Delete a shape:\n");
            printf("   D- Drawing the shapes:\n");
            printf("   E- Help:\n");
            printf("----------Your action----------\n");
            scanf(" %c", &direction);
        }

        if (direction == 'A') {
            printf("\n");
            printf("Please select an action:\n");
            printf("   1- Add a point\n");
            printf("   2- Add a line\n");
            printf("   3- Add circle\n");
            printf("   4- Add a square\n");
            printf("   5- Add a rectangle\n");
            printf("   6- Add a polygon\n");
            printf("   7- Return to the previous menu\n");
            printf("----------Your action----------\n");
            scanf(" %c", &action);

            while (((action < 49) || (action > 55))) {
                printf("\n");
                printf("Please select an action:\n");
                printf("   1- Add a point\n");
                printf("   2- Add a line\n");
                printf("   3- Add circle\n");
                printf("   4- Add a square\n");
                printf("   5- Add a rectangle\n");
                printf("   6- Add a polygon\n");
                printf("   7- Return to the previous menu\n");
                printf("----------Your action----------\n");
                scanf(" %c", &action);
            }

            if ((action) == '1') {
                int x1, y1;
                printf("Enter the coordinates of your point : px py\n");
                scanf("%d %d", &x1, &y1);
                Shape *s1 = create_point_shape(x1, y1);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);


            } else if ((action) == '2'){
                int x1, y1, x2, y2;
                printf("Enter the coordinates of your points : x1 y1 x2 y2\n");
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                Shape *s1 = create_line_shape(x1, y1, x2, y2);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);


            } else if ((action) == '3') {
                int x1, y1, radius;
                printf("Enter the coordiantes of the center of your circle and the radius : x1 y1 radius\n");
                scanf("%d %d %d", &x1, &y1, &radius);
                Shape *s1 = create_circle_shape(x1, y1, radius);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);


            } else if ((action) == '4') {
                int x1, y1, length;
                printf("Enter the coordinates of the left corner of your square and the size : x1 y1 size\n");
                scanf("%d %d %d", &x1, &y1, &length);
                Shape *s1 = create_square_shape(x1, y1, length);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);

            } else if ((action) == '5') {
                int x1, y1, width, height;
                printf("Enter the coordinates of the left corner of your rectangle and the width / heigth : x1 y1 width height\n");
                scanf("%d %d %d %d", &x1, &y1, &width, &height);
                Shape *s1 = create_rectangle_shape(x1, y1, width, height);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);


            } else if ((action) == '6') {
                int n;
                printf("Enter the number of points in your polygon (must be an even number)\n");
                scanf("%d", &n);
                Shape *s1 = create_polygon_shape(n);
                add_shape_to_area(a1, s1);
                draw_area(a1);
                print_area(a1);
                print_shape(s1);

            } else {

            }

        } else if ((direction == 'B') || (direction == 'b')) {
            display_shapes(a1);
        } else if ((direction == 'C') || (direction == 'c')) {
            int answer=0;
            printf("Which shapes do you want to delete ? (Enter the ID)):\n");
            scanf("%d",&answer);
            remove_shape_from_area(a1, answer);

        } else if ((direction == 'D') || (direction == 'd')) {
            draw_area(a1);
        } else if ((direction == 'E') || (direction == 'e')) {
            print_area(a1);
        } else if ((direction == 'F') || (direction == 'f')){
            selected = false;
        }
    }

    return 0;
}
