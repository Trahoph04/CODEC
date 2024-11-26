#ifndef ALISTLIB_H_INCLUDE
#define ALISTLIB_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int Position;
typedef int ElementType;

typedef struct {
    ElementType elements[MAXSIZE];
    Position size;
} List;


List L;
void makeNull(List *L){
	L->size = 0;
}

int len(List L){
	return L.size;
}

int empty(List L){
	return (L.size==0);
}

int fullList(List L){
	return (L.size == MAXSIZE);	
}

void print(List L){
	Position i;
	for(i = 1; i <= L.size; ++i){
		printf("%d ", L.elements[i - 1]);		
	} 
	printf("\n");
}

ElementType getAt(Position p, List L){
	return L.elements[p - 1];
}

Position first(List L){
	return 1;
}

Position endList(List L){
	return L.size + 1;
}

void setAt(Position p, ElementType x,List *L){
	 L->elements[p - 1] = x;
}

void insertAt(Position p, ElementType x, List *L){
	if(L->size == MAXSIZE)
		printf("Danh sach day! \n");
	else if(p < 1 || p > L->size + 1)
		printf("Vi tri khong hop le! \n");	
		else{
			Position q;
			for(q = L->size; q >= p; q--){
				L->elements[q] = L->elements[q - 1];
			}
			L->size++;
			L->elements[p - 1] = x;
		}
}
ElementType popAt(Position p, List *L){
	ElementType x;
	if(p>=1 && p<=L->size){
		x= L->elements[p-1];
		Position q;	
		for(q=p;q<endList(*L);q++)
			L->elements[q-1]=L->elements[q];	
		L->size--;
		return x;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
	
	
}

void insertFirst(ElementType x, List *L){
	insertAt(1, x, L);  
}

ElementType popFirst(List *L){
	return popAt(first(*L), L);
	
}

void append(ElementType x,List *L){
 	insertAt(L->size + 1, x, L);
}

ElementType popLast(List *L){
	return popAt(endList(*L), L);
}


ElementType Retrieve(Position p, List L){
	return L.elements[p-1];
}

Position next(Position p,List L){
	return p + 1;	
}

Position previous(Position p,List L){
	return p-1;	
}


Position locate(ElementType x, List L){
    Position p = first(L);
    Position q = endList(L);
    int found = 0;  
    while(p != q && !found){
        if(Retrieve(p, L) == x) 
            found = 1;
        else 
            p = next(p, L);  
    }
    if (!found)  
        p = endList(L);
    return p;
}
#endif 