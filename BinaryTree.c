#include <stdio.h>
#include <stdlib.h>
//code
typedef char TData;

typedef struct TNode {
    TData Data;
    struct TNode *left, *right;
} TNode;

typedef TNode* TTree;

void MakeNullTree(TTree *T) {
    *T = NULL;
}

int EmptyTree(TTree T) {
    return T == NULL;
}

TTree LeftChild(TTree n) {
    if (n != NULL) return n->left;
    else return NULL;
}

TTree RightChild(TTree n) {
    if (n != NULL) return n->right;
    else return NULL;
}

int IsLeaf(TTree n) {
    if (n != NULL)
        return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
    else
        return 0;
}

void PreOrder(TTree T) {
    if (T != NULL) {
        printf("%c ", T->Data);
        PreOrder(LeftChild(T));
        PreOrder(RightChild(T));
    }
}

void InOrder(TTree T) {
    if (T != NULL) {
        InOrder(LeftChild(T));
        printf("%c ", T->Data);
        InOrder(RightChild(T));
    }
}

void PosOrder(TTree T) {
    if (T != NULL) {
        PosOrder(LeftChild(T));
        PosOrder(RightChild(T));
        printf("%c ", T->Data);
    }
}

int nb_nodes(TTree T) {
    if (EmptyTree(T)) return 0;
    else return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

TTree Create2(TData v, TTree l, TTree r) {
    TTree N;
    N = (TNode*)malloc(sizeof(TNode));
    N->Data = v;
    N->left = l;
    N->right = r;
    return N;
}

int main() {
    TTree T1, T2, T3;
    
    T1 = Create2('A', NULL, NULL);
    T2 = Create2('B', NULL, NULL);
    T3 = Create2('C', T1, T2);

    printf("Duyệt tiền tự: ");
    PreOrder(T3);
    printf("\n");

    printf("Duyệt trung tự: ");
    InOrder(T3);
    printf("\n");

    printf("Duyệt hậu tự: ");
    PosOrder(T3);
    printf("\n");

    printf("Số nút trong cây: %d\n", nb_nodes(T3));

    return 0;
}
