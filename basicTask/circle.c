#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    const float PI = 3.141592654;
    float r;
    scanf ("%f", &r);
    float area = PI*r*r;
    printf("%0.4f", area);
    return 0;
}


