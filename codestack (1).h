#ifndef DASTACKLIB_H_INCLUDE
#define DASTACKLIB_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 2

typedef int ElementType;

typedef struct {
    ElementType *data;
    int top;
    int capacity;
} Stack;

/*
Initialize an empty stack
*/
void makeNull(Stack *S) {
    S->capacity = INITIAL_CAPACITY;
    S->data = (ElementType *)malloc(S->capacity * sizeof(ElementType));
    S->top = -1; // Indicates the stack is empty
}

/*
Check whether a stack is empty
*/
int isEmpty(Stack S) {
    return S.top == -1;
}

/*
Check whether a stack is full
*/
int isFull(Stack S) {
    return S.top == S.capacity - 1;
}

/*
Push x to the top of the stack
*/
void push(ElementType x, Stack *S) {
    if (isFull(*S)) {
        S->capacity *= 2; // Double the capacity
        S->data = (ElementType *)realloc(S->data, S->capacity * sizeof(ElementType));
        if (S->data == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    S->data[++S->top] = x;
}

/*
Return the element at the top and remove it
*/
ElementType pop(Stack *S) {
    if (isEmpty(*S)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE); // Handle underflow as needed
    }
    return S->data[S->top--];
}

/*
Free the memory allocated for the stack
*/
void freeStack(Stack *S) {
    free(S->data);
    S->data = NULL;
    S->top = -1;
    S->capacity = 0;
}

/*
Return the element at the top without removing it
*/
ElementType peek(Stack S) {
    if (isEmpty(S)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE); // Handle empty stack case
    }
    return S.data[S.top];
}

/*
Return the size of the stack
*/
int size(Stack S) {
    return S.top + 1;
}

/*
Print all elements in the stack
*/
void printStack(Stack S) {
    for (int i = S.top; i >= 0; i--) {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

#endif 
