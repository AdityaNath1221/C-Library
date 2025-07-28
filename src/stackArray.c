#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "stackArray.h"

int isEmpty(stack s){
    if(s.top == -1){
        return 1; 
    }
    else{
        return 0;
    }
}

int isFull(stack s){
    if(s.top == SIZE-1){
        return 1; 
    }
    else{
        return 0;
    }
}

int push(stack* s, int data){
    if(s->top==SIZE-1){
        printf("Size overflow.\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = data;
    return 1;
}

int pop(stack* s){
    if(s->top==-1){
        printf("No element left to pop.\n");
        return ERROR;
    }
    int temp = s->data[s->top];
    s->top--; 
    return temp;
}

int peek(stack s){
    if(s.top==-1){
        printf("There is nothing to peek.\n");
        return 0;
    }
    return s.data[s.top];
}

int size(stack s){
    return s.top+1;
}

void print_stack(stack s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    else{
        printf("Stack elements are: ");
        int i;
        for(i = s.top; i >= 0; i--){
            printf("%d\n", s.data[i]);
        }
        printf("\n");
        return;
    }
}