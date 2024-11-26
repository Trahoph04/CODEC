#include <stdio.h>
#include <stdlib.h>
#include "queuelib.h" 

#define MAX_STACK_SIZE 100 

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *S) {
    S->top = -1;
}

int isStackEmpty(Stack S) {
    return S.top == -1;
}

int isStackFull(Stack S) {
    return S.top == MAX_STACK_SIZE - 1;
}

void push(Stack *S, int x) {
    if (!isStackFull(*S)) {
        S->data[++(S->top)] = x;
    } else {
        printf("Stack is full. Cannot push %d.\n", x);
    }
}

int pop(Stack *S) {
    if (!isStackEmpty(*S)) {
        return S->data[(S->top)--];
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}

void reverseStackUsingQueue() {
    Stack S;
    CircularQueue Q;
    makeNull(&Q);
    initStack(&S);

    int num;
    printf("Enter integers to push onto stack (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        push(&S, num);
    }

    while (!isStackEmpty(S)) {
        enQueue(pop(&S), &Q);
    }

    while (!isEmpty(Q)) {
        int item;
        deQueue(&Q, &item);
        push(&S, item);
    }

    printf("Reversed stack elements:\n");
    while (!isStackEmpty(S)) {
        printf("%d ", pop(&S));
    }
    printf("\n");
}

void reverseQueueUsingStack() {
    CircularQueue Q;
    Stack S;
    makeNull(&Q);
    initStack(&S);

    int num;
    printf("Enter integers to enqueue (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        enQueue(num, &Q);
    }

    while (!isEmpty(Q)) {
        int item;
        deQueue(&Q, &item);
        push(&S, item);
    }

    while (!isStackEmpty(S)) {
        enQueue(pop(&S), &Q);
    }

    printf("Reversed queue elements:\n");
    while (!isEmpty(Q)) {
        int item;
        deQueue(&Q, &item);
        printf("%d ", item);
    }
    printf("\n");
}

void producerConsumer() {
    CircularQueue warehouse;
    makeNull(&warehouse);
    int capacity = 5;
    int num;

    printf("Producer-Consumer simulation (Enter integers to produce, -1 to stop):\n");
    
    while (1) {
        printf("Enter a number to produce (or -1 to stop): ");
        scanf("%d", &num);
        if (num == -1) break;

        if (isFull(warehouse)) {
            printf("Warehouse full! Cannot produce %d.\n", num);
        } else {
            enQueue(num, &warehouse);
            printf("Produced: %d\n", num);
        }

        if (!isEmpty(warehouse)) {
            int item;
            deQueue(&warehouse, &item);
            printf("Consumed: %d\n", item);
        }
    }
}

int main(int argc, char *argv[]) {
    reverseStackUsingQueue();
    reverseQueueUsingStack();
    producerConsumer();
    return 0;
}
