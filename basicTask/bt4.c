#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    float a,b,c;
    printf("Solving quadratic equation: ax^2 +bx +c\n");
    printf("a? b? c?\n");
    scanf("%f%f%f", &a, &b, &c);

    //your code...

    if (a == 0){
        printf("%0.4f \n", (-c)/b);
    }else{
        float x_one = (-b + sqrt(b*b - 4*a*c))/(2*a);
        float x_two = (-b - sqrt(b*b - 4*a*c))/(2*a);
        if (x_one == x_two){
            printf("Double roots: \n");
            printf("%0.4f \n", x_one);
        }else{
            if (isnan(x_one)){
                printf("Discriminant is a negative number. \n");
            }else{
                printf("%0.4f \n", x_one);
                printf("%0.4f \n", x_two);
            }   
        }
    }
    return 0;
}
