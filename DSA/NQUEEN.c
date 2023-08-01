#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4 // You can change N to solve for different board sizes

int x[N];

// Function to check whether a queen can be placed at position (k, i)
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

// Function to print the N-Queens solution
void printSolution(int n) {
    printf("Solution:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("Q\t");
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find all possible solutions for the N-Queens problem
void NQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                printSolution(n);
            } else {
                NQueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n = N;
    NQueen(1, n);
    return 0;
}
