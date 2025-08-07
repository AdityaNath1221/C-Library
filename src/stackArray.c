#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackArray.h"

#define ERROR1 -9999  // Underflow Error
#define ERROR2 -1    // Memory Allocation Error
#define ERROR3 -9998 // Overflow Error
#define ERROR INT_MIN

int initialize_stack(stack* s, int size){
    s->top = -1;
    s->size = size;
    s->st = (int*) malloc(size*sizeof(int));
    if(s->st == NULL){
        return ERROR2;
    }
    return 1;
}

/*      0 = true 1 = false     */

int isEmpty(stack s){
    if(s.top==-1)
        return 1;
    else
        return 0;
}

int isFull(stack s){
    if(s.top==s.size-1)
        return 1;
    else    
        return 0;
}

int push(stack* s, int data){
    if(isFull(*s)){
        return ERROR3;
    }
    s->top++;
    s->st[s->top] = data;
    return 1;
}

int pop(stack* s){
    if(isEmpty(*s)){
        return ERROR1;
    }
    int temp = s->st[s->top];
    s->top--;
    return temp;
}

int peek(stack s){
    if(isEmpty(s)){
        return ERROR1;
    }
    return(s.st[s.top]);
}