#ifndef QUEUELIB_H
#define QUEUELIB_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

void makeNull(CircularQueue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

bool isEmpty(CircularQueue Q) {
    return (Q.front == -1);
}

bool isFull(CircularQueue Q) {
    return ((Q.rear + 1) % MAX_SIZE == Q.front);
}

bool enQueue(int x, CircularQueue *Q) {
    if (isFull(*Q)) {
        printf("Queue is full. Cannot enqueue %d.\n", x);
        return false;
    }
    if (isEmpty(*Q)) {
        Q->front = 0;
    }
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    Q->data[Q->rear] = x;
    return true;
}

bool deQueue(CircularQueue *Q, int *item) {
    if (isEmpty(*Q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return false;
    }
    *item = Q->data[Q->front];
    if (Q->front == Q->rear) {
        Q->front = -1;
        Q->rear = -1;
    } else {
        Q->front = (Q->front + 1) % MAX_SIZE; 
    }
    return true;
}

bool append(int x, CircularQueue *Q) {
    return enQueue(x, Q);
}

#endif 
