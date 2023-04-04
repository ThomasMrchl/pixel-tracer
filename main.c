#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "polygon.h"
#include "shapes.h"

int main(){
    char direction;
    char action;

    printf("Please select an action:\n");
    printf("   A- Add a shape:\n");
    printf("   B- Display the list of shapes:\n");
    printf("   C - Delete a shape:\n");
    printf("   D- Drawing the shapes:\n");
    printf("   E- Help:\n");
    printf("----------Your action----------");
    scanf(" %c", &direction);



    while (((direction<65) || (direction>69))){

        printf("Please select an action:\n");
        printf("   A- Add a shape:\n");
        printf("   B- Display the list of shapes:\n");
        printf("   C - Delete a shape:\n");
        printf("   D- Drawing the shapes:\n");
        printf("   E- Help:\n");
        printf("----------Your action----------\n");
        scanf(" %c", &direction);

    }


    if (direction=='A') {
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

        while (((action<49) || (action>55))){

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

        if ((action)=='1') {
            int x1, y1;
            printf("Enter the coordinates of your point : px py\n");
            scanf("%d %d", &x1, &y1);
            Point *p1 = create_point(x1, y1);
            print_point(p1);


        } else if ((action)=='2'){
            int x1, y1, x2, y2;
            printf("Enter the coordinates of your points : x1 y1 x2 y2\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            Line *l1 = create_line(x1, y1, x2, y2);
            print_line(l1);
            delete_line(l1);

        } else if ((action)=='3'){

        } else if ((action)=='4'){

        } else if ((action)=='5'){

        } else if ((action)=='6'){

        } else {

        }

    } else if ((direction=='B') || (direction=='b')){
        /*display_shapes();*/
    } else if ((direction=='C') || (direction=='c')){
        /*display_shapes();
         * Then delete the one selected
         * */
    } else if ((direction=='D')||(direction=='d')){
        /* draw the shapes */
    } else if ((direction=='E')||(direction=='e')){
        /* show the help interface */
    } else {

    }


    return 0;
}
