#include <stdio.h>
#include <stdbool.h>

#define V 10 // Maximum number of vertices in the graph

void printSolution(int path[], int n);

/* A utility function to check if the vertex v can be added at index 'pos' in the Hamiltonian Path constructed so far (path[]) */
bool isSafe(int v, bool graph[V][V], int path[], int pos, int n) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

/* A recursive utility function to solve Hamiltonian Path problem */
void hamPathUtil(bool graph[V][V], int path[], int pos, int n, bool *found) {
    // base case: if all vertices are included in the Hamiltonian Path
    if (pos == n) {
        printSolution(path, n);
        *found = true;
        return;
    }

    // Try different vertices as the next candidate in Hamiltonian Path.
    // We don't try for 0 as we included 0 as starting point in the Hamiltonian Path
    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos, n)) {
            path[pos] = v;

            // recur to construct the rest of the path
            hamPathUtil(graph, path, pos + 1, n, found);

            // If adding vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }
}

/* This function solves the Hamiltonian Path problem using backtracking. It mainly uses hamPathUtil() to solve the problem. It returns false if there is no Hamiltonian Path possible, otherwise, it returns true and prints the path. */
void hamPath(bool graph[V][V], int n) {
    int path[V];
    for (int i = 0; i < n; i++)
        path[i] = -1;

    // Let's put vertex 0 as the first vertex in the path.
    path[0] = 0;

    bool found = false;
    hamPathUtil(graph, path, 1, n, &found);
    if (!found) {
        printf("\nNo solution exists\n");
    }
}

/* A utility function to print the solution */
void printSolution(int path[], int n) {
    printf("Solution Exists: Following is one Hamiltonian Path\n");
    for (int i = 0; i < n; i++)
        printf(" %d ", path[i]);

    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Taking input for the adjacency matrix of the graph
    bool graph[V][V];
    printf("Enter the adjacency matrix (0/1) for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the solution
    hamPath(graph, n);

    return 0;
}
