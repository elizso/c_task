#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int binarySearch(int a[], int n, int x){
    int low = 0;
    int high = n - 1;
    bool match = false;
    int mid;
    while (!match){
        mid = floorf((low + high) / 2);
        if (x > a[mid]){
            low = mid;
        }else if (x < a[mid]){
            high = mid;
        }else{
            match = true;
            return mid;
        }
    }
}

int main() {
    int arr[] = {0,1,8,12,12,18,18,45,55,99};
    int n=45;
    printf("%d is found at Index %d \n",n, binarySearch(arr,10,n));
    return 0;
 }