#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int array[10000];
int size = 0;

bool sort(){
    for (int i = 0; i < size - 1; i++){
        if (array[i] > array[i+1]){
            printf("array[i]: %d \n array[i+1]: %d \n", array[i], array[i+1]);
            return false;
        }
    }
    return true;
}

int main(){
    int swap = 0;
    int comp = 0;
    int i = 0;
    int num;
    FILE *fp;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL){
        perror("Error opening file");
        return 1;
    }else{
        for (i=0; i<10001; i++){
            fscanf(fp, "%d", &num);
            if (num != EOF){
                array[i] = num;
                size++;
            }else{
                break;
            }
        }
        for (i =0 ; i < size - 1; i++){
            for (int j = 0; j < size - i - 1; j++){
                if (array[j] > array[j+1]){
                    int data = array[j];
                    array[j] = array[j+1];
                    array[j+1] = data;
                    swap++;
                }
                comp++;
            }
        }
        for (int j = 0; j <= size-1; j++){
            printf("%d ", array[j]);
        }
        if (sort()){
            printf("\n Sorting order check: PASS \n");
            printf("Size: %d \n",size-1);
            printf("Swap counts: %d \n", swap);
            printf("Comparison count: %d \n", comp);
        }else{
            printf("Array is not sorted in order");
        }
        
        
    }
    fclose(fp);
    return 0;
}