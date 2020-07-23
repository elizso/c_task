#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define arrSize 400

int arr[arrSize];
int sort[arrSize];
int count = 0;

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


void merge(int l, int m, int r){
    int i, j, n1, n2;
    for (n1 = l, n2 = m + 1, i = l; n1 <= m && n2 <= r; i++){
        if (arr[n1] <= arr[n2]){
            sort[i] = arr[n1++];
        }else{
            sort[i] = arr[n2++];

        }
        count++;
    }
    while (n1 <= m){
        sort[i++] = arr[n1++];


    }
    while (n2 <= r){
        sort[i++] = arr[n2++];


    }
    for(i = l; i <= r; i++){
        arr[i] = sort[i];

    }
}

void mergeSort(int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);

        merge(l, m, r);
        
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
        for (int j = 0; j < arrSize; j++){
            printf("%d ", arr[j]);
        }
        mergeSort(0, arrSize-1);
    }
    for (int j = 0; j < arrSize; j++){
        printf("%d ", arr[j]);
    }
    printf("\nCounts: %d \n", count);
    if (sorted()){
        printf("\n Sorting order check: PASS \n");
        printf("Size: %d \n",arrSize);

    }else{
        printf("Array is not sorted in order\n");
    }

}