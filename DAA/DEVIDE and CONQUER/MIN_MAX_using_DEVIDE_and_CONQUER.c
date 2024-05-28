#include <stdio.h>
//#include <limits.h>

// Structure to hold the minimum and maximum values
typedef struct {
    int min;
    int max;
} MinMax;

// Function to find the minimum and maximum using Divide and Conquer
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, leftResult, rightResult;
    
    // If there is only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // If there are more than two elements
    int mid = (low + high) / 2;
    leftResult = findMinMax(arr, low, mid);
    rightResult = findMinMax(arr, mid + 1, high);

    // Compare results of the two halves
    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }

    return result;
}

int main() {
    int n;

    // Taking input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input for the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the minimum and maximum elements using Divide and Conquer
    MinMax result = findMinMax(arr, 0, n - 1);

    // Printing the results
    printf("Minimum element is %d\n", result.min);
    printf("Maximum element is %d\n", result.max);

    return 0;
}
