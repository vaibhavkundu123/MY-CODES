#include <stdio.h>

#define MAX_ITEMS 100

// Function to swap two integers
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items based on their profit per unit weight
void sortByRatio(int profits[], int weights[], float ratios[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                swap(&profits[j], &profits[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&ratios[j], &ratios[j + 1]);
            }
        }
    }
}

// Function to find maximum profit using fractional knapsack
float fractionalKnapsack(int capacity, int profits[], int weights[], int n) {
    float finalProfit = 0.0;
    float ratios[MAX_ITEMS];

    // Calculate ratios of profit to weight for each item
    for (int i = 0; i < n; i++) {
        ratios[i] = (float)profits[i] / weights[i];
    }

    // Sort items based on profit per unit weight (ratio)
    sortByRatio(profits, weights, ratios, n);

    int currentWeight = 0;

    // Fill the knapsack with items
    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            finalProfit += profits[i];
        } else {
            int remainingCapacity = capacity - currentWeight;
            finalProfit += ratios[i] * remainingCapacity;
            break;
        }
    }

    return finalProfit;
}

int main() {
    int capacity, n;
    int profits[MAX_ITEMS], weights[MAX_ITEMS];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &profits[i], &weights[i]);
    }

    float maxProfit = fractionalKnapsack(capacity, profits, weights, n);
    printf("Maximum profit in knapsack = %.2f\n", maxProfit);

    return 0;
}
