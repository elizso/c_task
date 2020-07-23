#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define arrSize 10000

int arr[arrSize];
int swap = 0;

bool sorted(){
    for (int i = 0; i < arrSize-1; i++){
        if (arr[i] > arr[i+1]){
            printf("array[i]: %d \n array[i+1]: %d \n", arr[i], arr[i+1]);
            printf("index of i: %d \n", i);
            return false;
        }
    }
    printf("went through sort()\n");
    return true;
}

int partition(int low, int high){
    int pivot = arr[high];
    int i = low;

    for (int j = low; j <= high; j++){
        if (arr[j] < pivot){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            swap++;
        }
    }
    arr[high] = arr[i];
    arr[i] = pivot;
    swap++;
    return i;
}

void quickSort(int low, int high){
    if(low < high){
        int pi = partition(low, high);        

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main(){
    int i;
    int num;
    FILE *fp;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL){
        perror("Error opening file");
        return 1;
    }else{
        for (i = 0; i < arrSize; i++){
            fscanf(fp, "%d", &num);
            if (num != EOF){
                arr[i] = num;
            }else{
                break;
            }
        }
        
        quickSort(0, arrSize);
    }
    for (int j = 0; j < arrSize; j++){
        printf("%d ", arr[j]);
    }
    printf("\nNumber of swaps: %d \n", swap);
    if (sorted()){
        printf("\n Sorting order check: PASS \n");
        printf("Size: %d \n",arrSize);

    }else{
        printf("Array is not sorted in order\n");
    }

}