#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int profits[], int n) {
    int i, w;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(profits[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][capacity];
}

int main() {
    int capacity, n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profits[n], weights[n];

    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &profits[i], &weights[i]);
    }

    int maxProfit = knapsack(capacity, weights, profits, n);
    printf("Maximum profit in knapsack = %d\n", maxProfit);

    return 0;
}
