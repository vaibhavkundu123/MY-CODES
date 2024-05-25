#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20 // Maximum number of vertices in the graph

void printSolutions(int solutions[][MAX_VERTICES], int numSolutions, int V);

/* Check if the current color assignment is safe for vertex v */
bool isSafe(int v, bool graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

/* Recursive function to solve the m-coloring problem */
void graphColoringUtil(bool graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V, int solutions[][MAX_VERTICES], int *numSolutions) {
    if (v == V) {
        for (int i = 0; i < V; i++)
            solutions[*numSolutions][i] = color[i];
        (*numSolutions)++;
        return;
    }

    /* Try different colors for vertex v */
    for (int c = 1; c <= m; c++) {
        /* Check if the assignment of color c to v is safe */
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;

            /* Recur to assign colors to the rest of the vertices */
            graphColoringUtil(graph, m, color, v + 1, V, solutions, numSolutions);

            /* If assigning color c doesn't lead to a solution, backtrack */
            color[v] = 0;
        }
    }
}

/* Main function to solve the m-coloring problem */
void graphColoring(bool graph[MAX_VERTICES][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    int solutions[MAX_VERTICES * MAX_VERTICES][MAX_VERTICES];
    int numSolutions = 0;

    /* Call the recursive utility function to solve the problem */
    graphColoringUtil(graph, m, color, 0, V, solutions, &numSolutions);

    /* Print the solutions */
    printf("All possible colorings of vertices:\n");
    printSolutions(solutions, numSolutions, V);
}

/* Function to print the solutions */
void printSolutions(int solutions[][MAX_VERTICES], int numSolutions, int V) {
    for (int i = 0; i < numSolutions; i++) {
        printf("Solution %d: ", i + 1);
        for (int j = 0; j < V; j++)
            printf("%d ", solutions[i][j]);
        printf("\n");
    }
}

int main() {
    int V, m;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    bool graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (0/1):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
