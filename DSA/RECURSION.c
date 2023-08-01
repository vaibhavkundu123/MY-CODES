#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void towerOfHanoi(int n, char beg, char aux, char end)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c \n", beg, end);
        return;
    }
    towerOfHanoi(n - 1, beg, end, aux);
    printf("Move disk %d from %c to %c \n", n, beg, end);
    towerOfHanoi(n - 1, aux, beg, end);
}

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

int main()
{
    int choice, n, a, b;
    while (1)
    {
        printf("\n");
        printf("Enter 1 to find the factorial of a number \n");
        printf("Enter 2 to find the nth term of the fibonacci series \n");
        printf("Enter 3 to find the gcd of two numbers \n");
        printf("Enter 4 to find the tower of hanoi \n");
        printf("Enter 5 to find all possible solutions for the N-Queens problem \n");
        printf("Enter 6 to exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &n);
            printf("The factorial of %d is %d \n", n, factorial(n));
            break;
        case 2:
            printf("Enter the number of terms in the Fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci series: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", fibonacci(i));
                if(i == n - 1) {
                    printf("\n");
                    printf("The %dth term of the fibonacci series is %d \n", n, fibonacci(n - 1));
                    continue;
                }
            }
            break;
        case 3:
            printf("Enter the two numbers: ");
            scanf("%d %d", &a, &b);
            printf("The gcd of %d and %d is %d \n", a, b, gcd(a, b));
            break;
        case 4:
            printf("Enter the number of disks: ");
            scanf("%d", &n);
            towerOfHanoi(n, 'A', 'B', 'C');
            break;
        case 5:
            n = N;
            NQueen(1, n);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
        }
    }
    return 0;
}