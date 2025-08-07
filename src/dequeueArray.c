#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dequeueArray.h"

#define ERROR1 -1 //Memory allocation error
#define ERROR2 -9998 //Overflow error
#define ERROR3 -9999 //Underflow error

int initialize_dequeue(dequeue* queue, int size){
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->queue = (int*) malloc(size*sizeof(int));
    if(queue->queue == NULL){
        return ERROR1;
    }
    return 1;
}

int is_empty(dequeue queue){
    if(queue.front==-1 && queue.rear==-1)
        return 1;
    else    
        return 0;
}

int is_full(dequeue queue){
    if((queue.rear+1)%queue.size == queue.front)
        return 1;
    else 
        return 0;
}

int enqueue_front(dequeue* queue, int data){
    if(is_full(*queue)==1){
        return ERROR2;
    }
    if(is_empty(*queue)==1){
        queue->front = queue->rear = 0;
    }
    else if(queue->front==0){
        queue->front = queue->size-1;
    }
    else{
        queue->front--;
    }
    queue->queue[queue->front] = data;
    return 1;
}

int enqueue_rear(dequeue* queue, int data){
    if(is_full(*queue)==1){
        return ERROR2;
    }
    if(is_empty(*queue)==1){
        queue->front = queue->rear = 0;
    }
    else{
        queue->rear = (queue->rear+1)%queue->size ;
    }
    queue->queue[queue->rear] = data;
    return 1;
}

int dequeue_front(dequeue* queue){
    if(is_empty(*queue)==1){
        return ERROR3;
    }
    int temp = queue->queue[queue->front];
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else{
        queue->front = (queue->front+1)%queue->size;
    }
    return temp;
}

int dequeue_rear(dequeue* queue){
    if(is_empty(*queue)==1){
        return ERROR3;
    }
    int temp = queue->queue[queue->rear];
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else if(queue->rear == 0){
        queue->rear = queue->size - 1;
    }
    else{
        queue->rear--;
    }
    return temp;
}