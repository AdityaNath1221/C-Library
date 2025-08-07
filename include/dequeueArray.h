#ifndef DEQUEUEARRAY_H
#define DEQUEUEARRAY_H

typedef struct dequeue{
    int front, rear;
    int *queue;
    short int size;
}dequeue;

int initialize_dequeue(dequeue* queue, int size);
int is_empty(dequeue queue);
int is_full(dequeue queue);
int enqueue_front(dequeue* queue, int data);
int enqueue_rear(dequeue* queue, int data);
int dequeue_front(dequeue* queue);
int dequeue_rear(dequeue* queue);

#endif