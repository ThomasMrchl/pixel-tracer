#include <stdio.h>
#include "point.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "polygon.h"

int main(){
    char direction;

    printf("Please select an action:\n");
    printf("   A- Add a shape:\n");
    printf("   B- Display the list of shapes:\n");
    printf("   C - Delete a shape:\n");
    printf("   D- Drawing the shapes:\n");
    printf("   E- Help:\n");

    scanf(" %c", &direction);



    while (direction!='A' || direction!='B' || direction!='C' || direction!='D' || direction!='E')
    if ((direction=='A') || (direction=='a')){
        printf("Please select an action:");
        printf("   1- Add a point");
        printf("   2- Add a line");
        printf("   3- Add circle");
        printf("   4- Add a square");
        printf("   5- Add a rectangle");
        printf("   6- Add a polygon");
        printf("   7- Return to the previous menu");

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
