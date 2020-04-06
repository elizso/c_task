#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b;
    char op;

    printf("Enter a simple math expression with two operands (Example: 3 + 2)\nSeparate them with a space\n");
    printf("(Operator supported: +  -  *  / ^)\n\n");

    //you code here...
    scanf("%f %c %f",&a, &op, &b);
    switch(op){
        case '+':
            printf("Result: %0.2f + %0.2f = %0.2f \n", a, b, a+b);
            break;
        case '-':
            printf("Result: %0.2f - %0.2f = %0.2f \n", a, b, a-b);
            break;
        case '*':
            printf("Result: %0.2f * %0.2f = %0.2f \n", a, b, a*b);
            break;
        case '/':
            printf("Result: %0.2f / %0.2f = %0.2f \n", a, b, a/b);
            break;
        case '^':
            printf("Result: %0.2f ^ %0.2f = %0.2f \n", a, b, pow(a,b));
            break;
        default:
            printf("Result: %0.2f %c %0.2f = Error! operator is not correct. \n", a, op, b);

    }

    system("wait");
    return 0;
}
