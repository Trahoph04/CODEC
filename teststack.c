#include <stdio.h>
#include <stdlib.h>
#include "dastacklib.h"

int Fibo(int n) {
    Stack S;
    makeNull(&S);
    
    if (n == 0) {
        freeStack(&S);
        return 0;
    }
    if (n == 1) {
        freeStack(&S);
        return 1;
    }

    push(0, &S); 
    push(1, &S); 
    
    for (int i = 2; i <= n; i++) {
        int a = pop(&S);
        int b = pop(&S);
        int fib = a + b; 
        push(b, &S); 
        push(fib, &S); 
    }

    int result = pop(&S);
    freeStack(&S);
    return result;
}


int C(int k, int n) {
    if (k < 0 || k > n) {
        return 0;
    }

    Stack S;
    makeNull(&S);

    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        push(result, &S); 
        result /= (i + 1);
    }

    while (!isEmpty(S)) {
        result = pop(&S);
    }

    freeStack(&S);
    return result;
}

int main(int argc, char *argv[]) {
    int n, k;

    printf("Enter a number for Fibonacci calculation (n): ");
    scanf("%d", &n);
    printf("Fibo(%d) = %d\n", n, Fibo(n));


    printf("Enter two numbers for C(k, n) calculation (k n): ");
    scanf("%d %d", &k, &n);
    printf("C(%d, %d) = %d\n", k, n, C(k, n));

    return 0;
}
