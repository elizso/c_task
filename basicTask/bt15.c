#include <stdio.h>
#include <math.h>

/*Declare a struct named Point here*/
struct Point
{
    float x, y;
};
/*Declare the functions here*/
int midPoint(struct Point coor1, struct Point coor2){
    float mx, my;
    mx = (coor1.x + coor2.x)/2;
    my = (coor1.y + coor2.y)/2;
    printf("Midpoint of Point 1 and Point 2: (%.2f, %.2f) \n", mx, my);
    return 0;
}

int distance(struct Point coor1, struct Point coor2){
    float dist;
    dist = sqrt(pow((coor1.x-coor2.x), 2)+pow((coor1.y-coor2.y), 2));
    printf("Distance between Point 1 and Point 2: %.2f\n", dist);
    return 0;
}

int formula(struct Point coor1, struct Point coor2){
    float slope, c;
    char sign;
    slope = (coor2.y-coor1.y)/(coor2.x-coor1.x);
    c = (coor1.y - slope * coor1.x);
    
    if (c >= 0){
        sign = '+';
    }else{
        sign = ' ';
    }
    if (c == 0){
        if (slope == 1){
            printf("The formula is x - y = 0");
        }else if (slope == -1){
            printf("The formula is -x - y = 0 ");
        }
        else if (slope == 0){
            printf("The formula is - y = 0");
        }else{
            printf("The formula is %.2fx - y = 0", slope);
        }
    }else{
        if (slope == 1){
            printf("The formula is x - y%c%.2f = 0", sign, c);
        }else if (slope == -1){
            printf("The formula is -x - y%c%.2f = 0 ", sign, c);
        }
        else if (slope == 0){
            printf("The formula is - y %c %.2f = 0", sign, c);
        }else{
            printf("The formula is %.2fx - y %c %.2f = 0", slope, sign, c);
        }

    }
    printf("\n");
    return 0;
}

void sameLine(struct Point coor1, struct Point coor2, struct Point coor3){
    float side1, side2, side3, s, area;
    side1 = sqrt(pow((coor2.x-coor1.x), 2) + pow((coor2.y - coor1.y), 2));
    side2 = sqrt(pow((coor3.x-coor2.x), 2) + pow((coor3.y - coor2.y), 2));
    side3 = sqrt(pow((coor1.x-coor3.x), 2) + pow((coor1.y - coor3.y), 2));
    s = (side1 + side2 + side3) / 2;
    area = sqrt(s * (s-side1) * (s-side2) * (s-side3));
    if (area == 0){
        printf("The three points are on the same line!\n");
        formula(coor1, coor2);
    }
}

int main()
{
    struct Point test1, test2, test3; //Point is not declared yet, try to look up how it should be created.
    printf("Enter the coordinate of Point 1: ");
    scanf("%f %f", &test1.x, &test1.y);
    printf("Enter the coordinate of Point 2: ");
    scanf("%f %f", &test2.x, &test2.y);
    printf("Enter the coordinate of Point 3: ");
    scanf("%f %f", &test3.x, &test3.y);
    //Resume your code here
    midPoint(test1, test2);
    distance(test1, test2);
    formula(test1, test2);
    sameLine(test1, test2, test3);
    
    
    return 0;
}


