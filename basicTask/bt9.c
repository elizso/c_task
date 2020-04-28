#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num[5];
    int length_of_array = 0;
    float sum, average, max, min;

    /* Print basic information about the array */
    printf("---------------------------------------\n");
    printf("Size of array num[]:\t%2d bytes\n", sizeof(num));
    printf("Size of each element:\t%2d bytes\n", sizeof(num[0]));

    length_of_array = sizeof(num)/sizeof(num[0]);
    printf("The array num[] has %d elements\n",length_of_array);
    printf("---------------------------------------\n\n");


    /* Print basic information about the array */
    printf("Getting numbers into the array...\n\n");

    int i;
    for (i=0; i<length_of_array; i++) {
        printf("num[%d] = ", i);
        scanf("%f", &num[i]);
    }

    printf("\nContent stored in the array...\n");
    printf("---------------------------------------\n");
    /* Your code to display the output */
    printf("%-12s%-12s%-12s%-12s%-12s\n", "num[0]", "num[1]", "num[2]", "num[3]", "num[4]");
    printf("%-12.2f%-12.2f%-12.2f%-12.2f%-12.2f\n", num[0], num[1], num[2], num[3], num[4]);
    printf("\n---------------------------------------\n");

    
    /* Your code to display the output */
    max = 0;
    min = 0;
    sum = 0;
    average = 0;
    for (i=0; i< length_of_array; i++){
        sum += num[i];
        average += num[i];
        if (num[i] > max){
            max = num[i];
        }
        if (i==0){
            min = num[i];
        }else if (num[i] < min){
            min = num[i];
        }

    }
    average = average / length_of_array;

    printf("Max = %.2f\n", max);
    printf("Min = %.2f\n", min);
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", average);
   


    //system("pause");
    return 0;
}