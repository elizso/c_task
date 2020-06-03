#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int size = 0;
int array[10000];

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
    int num, key, j, i;
    FILE *fp;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL){
        perror("Error opening file");
        return 1;
    }else{
        //get the numbers from text file
        for (i=0; i<10001; i++){
            fscanf(fp, "%d", &num);
            if (num != EOF){
                array[i] = num;
                size++;
            }else{
                break;
            }
        }
        //insertion sort
        for (i = 1; i < size; i++){
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
        //print array
        for (int j = 0; j < size; j++){
            printf("%d ", array[j]);
        }
    }
    if (sort()){
        printf("array is sorted");
    }
    fclose(fp);
    return 0;
}