#include <stdio.h>
//#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int V, E;
    struct Edge *edges;
};

void BellmanFord(struct Graph* graph, int source) {
    int V = graph->V;
    int E = graph->E;
    int distances[MAX_VERTICES];

    // Initialize distances from source to all other vertices as INFINITE
    for (int i = 0; i < V; ++i)
        distances[i] = INT_MAX;
    distances[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = graph->edges[j].source;
            int v = graph->edges[j].destination;
            int weight = graph->edges[j].weight;
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v])
                distances[v] = distances[u] + weight;
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = graph->edges[i].source;
        int v = graph->edges[i].destination;
        int weight = graph->edges[i].weight;
        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            printf("Graph contains negative weight cycle!\n");
            return;
        }
    }

    // Print the distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distances[i]);
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    printf("Enter the number of vertices: ");
    scanf("%d", &graph->V);

    printf("Enter the number of edges: ");
    scanf("%d", &graph->E);

    graph->edges = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

    printf("Enter the edges as (source destination weight):\n");
    for (int i = 0; i < graph->E; ++i) {
        scanf("%d %d %d", &graph->edges[i].source, &graph->edges[i].destination, &graph->edges[i].weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    BellmanFord(graph, source);

    free(graph->edges);
    free(graph);

    return 0;
}
