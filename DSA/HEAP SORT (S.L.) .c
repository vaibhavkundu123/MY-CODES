#include <stdio.h>

int TREE[100];
int N;
int ITEM;
int A[100];

void INSHEAP (void) {
    int PTR, PARENT;
    PTR = N;
    while (PTR > 0) {
        PARENT = (PTR - 1) / 2;
        if (ITEM <= TREE[PARENT]) {
            TREE[PTR] = ITEM;
            return;
        }
        TREE[PTR] = TREE[PARENT];
        PTR = PARENT;
    }
    TREE[0] = ITEM;
}

void DELHEAP (void) {
    int LEFT, RIGHT, PTR, LAST;
    ITEM = TREE[0];
    LAST = TREE[N - 1];
    N = N - 1;
    PTR = 0;
    LEFT = 2 * PTR + 1;
    RIGHT = 2 * PTR + 2;
    while (RIGHT <= N) {
        if (LAST >= TREE[LEFT] && LAST >= TREE[RIGHT]) {
            TREE[PTR] = LAST;
            return;
        }
        if (TREE[RIGHT] <= TREE[LEFT]) {
            TREE[PTR] = TREE[LEFT];
            PTR = LEFT;
        } else {
            TREE[PTR] = TREE[RIGHT];
            PTR = RIGHT;
        }
        LEFT = 2 * PTR + 1;
        RIGHT = 2 * PTR + 2;
    }
    if (LEFT == N && LAST < TREE[LEFT]) {
        TREE[PTR] = TREE[LEFT];
        PTR = LEFT;
    }
    TREE[PTR] = LAST;
}

void HEAPSORT (void) {
    int I;
    for (I = 0; I < N; I++) {
        INSHEAP();
    }
    for (I = 0; I < N; I++) {
        DELHEAP();
    }
}

int main () {
    int I;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    printf("Enter the elements: ");
    for (I = 0; I < N; I++) {
        scanf("%d", &A[I]);
    }
    for (I = 0; I < N; I++) {
        ITEM = A[I];
        INSHEAP();
    }
    printf("Sorted array: ");
    for (I = 0; I < N; I++) {
        printf("%d ", TREE[I]);
    }
    printf("\n");
    return 0;
}