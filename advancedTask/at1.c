#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char stack[10001];
int top = -1;

int isEmpty(void);
void push(char ch);
char pop(void);
void printStack(void);

int isEmpty(void) {
   //your code
   if (top == -1){
       return 1;
   }else{
       return 0;
   }
}

void push(char ch) {
   //your code
    top++;
    stack[top] = ch;
}

char pop(void) {
    //your code
    char data;
    if (!isEmpty()){
        data = stack[top];
        top--;
        return data;
    } else {
        printf("Stack is empty.");
        return ' ';
    }
}

void printStack(void) {
   //your code
   if (!isEmpty()){
       int i = 0;
       while (stack[i] != 0){
           printf("%c ", stack[i]);
           i++;
       }
   }
}

char peek(void){
    //your code
    return stack[top];
}

bool match(char char1, char char2){
    if (char1 == '{' && char2 == '}'){
        return true;
    }else if (char1 == '(' && char2 == ')'){
        return true;
    }else if (char1 == '[' && char2 == ']'){
        return true;
    }else{
        return false;
    }
}

int main(){
    char input[20001];
    int i = 0;
    bool balance = true;
    fgets(input, 10001, stdin);
    while (input[i] != 0){
        if (input[i] == '{' || input[i] == '(' || input[i] == '['){
            push(input[i]);
        }else if (input[i] == '}' || input[i] == ')' || input[i] == ']'){
            if (match(peek(), input[i])){
                pop();
                balance = true;
            }else{
                balance = false;
                break;
            }
        }
        i++;
    }
    if (balance && top == -1){
        printf("Yes");
    }else{
        printf("No");
    }
}