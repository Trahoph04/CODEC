#include <stdio.h>
#include "plistlib.h"

void appendList(int a[], int n, List *L) {
    makeNull(L);
    for (int i = 0; i < n; i++) {
        append(a[i], L);
    }
}

void reverseList(int a[], int n, List *L) {
    makeNull(L);
    for (int i = n - 1; i >= 0; i--) {
        append(a[i], L);
    }
}

void bubbleSort(List *L) {
    if (empty(*L)) return;

    int swapped;
    do {
        swapped = 0;
        for (Position i = 0; i < len(*L) - 1; i++) {
            if (getAt(i, *L) > getAt(i + 1, *L)) {
                int temp = getAt(i, *L);
                setAt(i, getAt(i + 1, *L), L);
                setAt(i + 1, temp, L);
                swapped = 1;
            }
        }
    } while (swapped);
}

int main() {
    List L1;
    int a[] = {32, 51, 27, 83, 66, 11, 45, 75};
    
	appendList(a, sizeof(a)/sizeof(int), &L1);

	print(L1);

	reverseList(a, sizeof(a)/sizeof(int), &L1);

	print(L1);

	insertAt(3,22,&L1);

	print(L1);

	bubbleSort(&L1);

	print(L1);

    return 0;
}

