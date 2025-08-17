#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MEM_ERROR INT_MIN
#define UNDERFLOW_ERROR (INT_MIN+1)
#define INVALID_POS_ERROR (INT_MIN+2)
#define POS_OOB_ERROR (INT_MIN+3)
#define SUCCESS 1
#define FAILURE 0

typedef struct node{
    int data;
    struct node *next;
}node;

int add_beg(node** head, int data);
int add_end(node** head, int data);
int add_pos(node** head, int data, int pos);
int rem_beg(node** head);
int rem_end(node** head);
int rem_pos(node** head, int pos);
int display_list(node* head);

#endif