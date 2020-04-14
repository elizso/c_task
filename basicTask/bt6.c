#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int st, col, mult, i, j;
    printf("Starting from? [1-90]   ");
    scanf("%d", &st);
    printf("No. of columns? [1-10]  ");
    scanf("%d", &col);
    printf("Multiples up to? [1-99] ");
    scanf("%d", &mult);

    for (j=1; j<=mult; j++){
        for (i=st; i<=st+col; i++){
            printf(" %dx%d = %d\t|", i, j, i*j);
        }
        printf("\n");
    }
}