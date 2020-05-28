#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char queue[10000];
int front = -1;
int rear = -1;

bool isEmpty();
bool isFull();
void enQueue(char ch);
char deQueue();
void printQueue();

bool isEmpty(){
    if (front == -1 || front > rear){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if (front == 9999){
        return true;
    }else{
        return false;
    }
}

void enQueue(char ch){
    if ((front == 0 && rear == 9999) || (front == rear + 1)){
        printf("queue is full");
    }else if (rear == -1){
        rear++;
        front++;
    }else if (rear == 9999 && front > 0){
        rear = 0;
    }else{
        rear++;
    }
    queue[rear] = ch;
    
}

char deQueue(){
    char data;
    if (isEmpty() == false){
        if (front == rear){
            data = queue[front];
            front --;
            rear --;
            return data;
        }else{
            data = queue[front];
            front ++;
            return data;
        }
    }else{
        return '!';
    }

}

void printQueue(){
    for (int i = front; i <= rear; i++){
        printf("%c", queue[i]);
    }
}

int main(){
    char input = 'n';
    scanf("%s", &input);
    enQueue(input);
    printQueue();
    deQueue();
    printQueue();

        
}