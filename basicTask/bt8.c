#include <stdio.h>
#include <stdlib.h>

void patternOne(int row){
    printf("\nPattern #1\n");
    for (int i = 1; i <= row; i++){
        int j;
        for (j = row; j >= i; j--){
            //print corresponding number of spaces
            printf(" ");
        }
        for (int k = i; k >= 1; k--){
            //print from number of the row to 1
            printf("%d", k);
        }
        printf("\n");
    }
    printf("\n");
}

void patternTwo(int row){
    printf("\nPattern #2\n");
    int k = 1; //counter 
    for (int i = 1; i <= row; i++){
        for (int j = 0; j < i; j++){
            printf("%d ", k);
            k++;
        }
        printf("\n");
    }
    printf("\n");
}

void patternThree(int row){
    printf("\nPattern #3\n");
    for (int i = 1; i <= row; i++){
        for (int j = 1; j <= row; j++){
            if (i==j){
                //check for number equal to row number i
                printf("%d", j);
            }
            else if(row+1-j==i){
                //check if the number equals to the second number from the same row
                printf("%d", j);
            }
            else{
                //print space between the numbers
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
void patternFour(int row){
    printf("\nPattern #4\n");
    for (int i = 1; i <= row; i++){
        for (int j = row-i; j >= 0; j--){
            //printing corresponding number of spaces for each line. 
            printf(" ");
        }
        int k;
        for (k = 1; k <= i; k++){
            //print from 1 to i
            printf("%d", k);
        }
        for (k = i-1; k >= 1; k--){
            //print from i-1 to 1
            printf("%d", k);
        }
        printf("\n");
    }
    printf("\n");
}

void start(void){
    int row;
    char again;
    printf("Number of rows? (1-9)   ");
    scanf(" %d", &row);
    patternOne(row);
    patternTwo(row);
    patternThree(row);
    patternFour(row);
    printf("\nAgain? [Y/N] ");
    scanf(" %c", &again);
    if (again == 'Y' || again == 'y'){
        start();
    }else{
        system("wait");
    }
}

int main(){
    start();
}