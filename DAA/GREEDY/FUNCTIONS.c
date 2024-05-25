#include <stdio.h>

int heapify(int A[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;
    if (left < n && A[left] < A[smallest]) {
        smallest = left;
    }
    if (right < n && A[right] < A[smallest]) {
        smallest = right;
    }
    if (smallest!= i) {
        temp = A[smallest];
        A[smallest] = A[i];
        A[i] = temp;
        heapify(A, n, smallest);
    }
}

int build_min_priority_queue(int A[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
}

int Enqueue(int A[], int n, int x) {
    int counter = -1;
    int temp;
    if(counter == n - 1) {
        printf("Overflow\n");
    }
    else {
        A[++counter] = x;
        int child = counter;
        int parent = (child-1)/2;
        while(child > 0 && A[parent] < A[child]) {
            temp = A[parent];
            A[parent] = A[child];
            A[child] = temp;
            child = parent;
            parent = (child-1)/2;
        }
    }
}

int heap_decrease(int A[], int i, int x) {
    int temp;
    A[i] = x;
    int child = i;
    int parent = (child-1)/2;
    while(child > 0 && A[parent] < A[child]) {
        temp = A[parent];
        A[parent] = A[child];
        A[child] = temp;
        child = parent;
        parent = (child-1)/2;
    }
}

int extract_min(int A[], int counter) {
    if(counter == -1) {
        printf("Underflow\n");
    }
    else {
        printf("Minimum element: %d\n", A[0]);
        A[0] = A[counter];
        counter--;
        heapify(A, counter+1, 0);
    }
}