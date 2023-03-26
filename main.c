#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "polygon.h"

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
            int x1, x2;
            printf("Enter the coordinates of the point x1 y1 :\n");
            scanf("%d %d", &x1, &x2);
            struct point *p = create_point(x1, x2);
            printf("Point: (%d, %d)\n", p->px, p->py);
            free(p);
        } else if ((action)=='2'){

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
