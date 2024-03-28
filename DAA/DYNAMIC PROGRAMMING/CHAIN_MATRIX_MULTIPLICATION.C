#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications needed to multiply the chain of matrices
int matrixChainOrder(int p[], int n) {
    int m[n][n]; // Array to store the minimum number of scalar multiplications needed
    
    // Initialize the m[i][i] entries to 0 as multiplying one matrix doesn't cost anything
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // 'l' is the chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX; // Set the minimum value initially to the maximum possible integer

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // Return the minimum number of scalar multiplications needed
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int arr[n + 1]; // Array to store dimensions of matrices
    printf("Enter the dimensions of matrices (separate by space): ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, n + 1));

    return 0;
}
