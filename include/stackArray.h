#ifndef STACKARRAY_H
#define STACKARRAY_H

#define SIZE 10
#define ERROR INT_MIN

typedef struct stack{
    int data[SIZE];
    int top;
}stack;

int isEmpty(stack s);
int isFull(stack s);
int push(stack* s, int data);
int pop(stack* s);
int peek(stack s);
int size(stack s);
void print_stack(stack s);

#endif