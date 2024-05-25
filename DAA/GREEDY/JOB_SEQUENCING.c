#include <stdio.h>

#define MAX_JOBS 100

// Structure to represent a job
struct Job {
    char id;        // Job ID
    int deadline;   // Deadline of job
    int profit;     // Profit of job
};

// Function to sort jobs based on their profit in non-increasing order
void sortByProfit(struct Job jobs[], int n) {
    struct Job temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Function to find the maximum deadline from the given jobs
int findMaxDeadline(struct Job jobs[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    return maxDeadline;
}

// Function to schedule jobs to maximize profit and calculate total profit
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs based on profit
    sortByProfit(jobs, n);

    // Find maximum deadline
    int maxDeadline = findMaxDeadline(jobs, n);

    // Array to store the result of scheduling
    char result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        result[i] = '\0';

    int totalProfit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (result[j] == '\0') {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("Scheduled Jobs:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != '\0')
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    if (n > MAX_JOBS) {
        printf("Number of jobs exceeds maximum limit.\n");
        return 1;
    }

    struct Job jobs[MAX_JOBS];

    printf("Enter job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    printf("\nOriginal Jobs:\n");
    for (int i = 0; i < n; i++) {
        printf("Job %c: Deadline = %d, Profit = %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    printf("\n");

    jobSequencing(jobs, n);
    

    return 0;
}
