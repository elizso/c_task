#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int max = 0;
    int min = 10000;
    float sum = 0;
    int count = 0;
    int arr[2][10000];
    int read;
    FILE *fp;
    fp = fopen("numbers.txt", "r");
    if (fp == NULL){
        printf("File can't be open");
        return 1;
    }
    for (int i = 0; i < 10000; i++){
        fscanf(fp, "%d", &read);
        if (read != EOF){
            sum += read;
            if (read > max){
                max = read;
            }
            if (read < min){
                min = read;
            }
            count += 1;
        }else{
            break;
        }
        
    }
    fclose(fp);
    printf("Arithmetic mean: %.2f\n", sum/count);
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    
}