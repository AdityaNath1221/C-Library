#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackArray.h"

#define SIZE 5
#define ERROR INT_MIN

int initialize_stack(stack* s){
    s->top = -1;
    s->st = (int*) malloc(SIZE*sizeof(int));
    if(s->st == NULL){
        printf("STACK ERROR: Memory could not be allocated for stack.\n");
        return 0;
    }
    return 1;
}

int isEmpty(stack s){
    if(s.top==-1)
        return 1;
    else
        return 0;
}

int isFull(stack s){
    if(s.top==SIZE-1)
        return 1;
    else    
        return 0;
}

int push(stack* s, int data){
    if(!isFull){
        printf("OVERFLOW ERROR: Stack Full.\n");
        return 0;
    }
    s->top++;
    s->st[s->top] = data;
    return 1;
}

int pop(stack* s){
    if(!isEmpty){
        printf("UNDERFLOW ERROR: Stack Empty.\n");
        return ERROR;
    }
    int temp = s->st[s->top];
    s->top--;
    return temp;
}

int peek(stack s){
    if(!isEmpty){
        printf("STACK ERROR: No elements in stack.\n");
        return ERROR;
    }
    return(s.st[s.top]);
}