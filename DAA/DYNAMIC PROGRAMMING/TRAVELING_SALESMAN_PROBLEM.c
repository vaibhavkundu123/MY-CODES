#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n, minCost = 999;

void input() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter costs for city %d: ", i+1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void tsp(int city, int cost) {
    visited[city] = 1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            tsp(i, cost + graph[city][i]);
            count++;
        }
    }

    if (count == 0) {
        if (cost + graph[city][0] < minCost) {
            minCost = cost + graph[city][0];
        }
    }

    visited[city] = 0;
}

int main() {
    input();
    tsp(0, 0);
    printf("Minimum cost for Traveling Salesman Problem is %d\n", minCost);
    return 0;
}
