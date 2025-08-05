#ifndef STACKARRAY_H
#define STACKARRAY_H

typedef struct stack{
    int* st;
    int top;
}stack;

int initialize_stack(stack* s);
int isEmpty(stack s);
int isFull(stack s);
int push(stack* s, int data);
int pop(stack* s);
int peek(stack s);

#endif