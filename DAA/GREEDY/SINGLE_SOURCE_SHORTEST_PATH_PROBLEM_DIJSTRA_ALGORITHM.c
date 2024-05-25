#include <stdio.h>
#define INFINITY 99
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int scr);

int main() {
    int Graph[MAX][MAX], i, j, n, u;
    
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &Graph[i][j]);
    
    printf("\nEnter the starting node: ");
    scanf("%d", &u);
    
    dijkstra(Graph, n, u);
    
    return 0;
}

void dijkstra(int Graph[MAX][MAX], int n, int scr) {
    int cost[MAX][MAX], dist[MAX], pred[MAX];
    int visited[MAX], count, mindist, nextnode, i, j;
    
    // Create the cost matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cost[i][j] = (Graph[i][j] == 0) ? INFINITY : Graph[i][j];
    
    // Initialize pred[], distance[], and visited[]
    for(i = 0; i < n; i++) {
        dist[i] = cost[scr][i];
        pred[i] = scr;
        visited[i] = 0;
    }
    
    dist[scr] = 0;
    visited[scr] = 1;
    count = 1;
    
    while(count < n) {
        mindist = INFINITY;
        
        // Nextnode gives the node at minimum distance
        for(i = 0; i < n; i++)
            if(dist[i] < mindist && !visited[i]) {
                mindist = dist[i];
                nextnode = i;
            }
        
        // Check if a better path exists through nextnode
        visited[nextnode] = 1;
        for(i = 0; i < n; i++)
            if(!visited[i] && mindist + cost[nextnode][i] < dist[i]) {
                dist[i] = mindist + cost[nextnode][i];
                pred[i] = nextnode;
            }
        
        count++;
    }
    
    // Print the path and distance of each node
    for(i = 0; i < n; i++)
        if(i != scr) {
            printf("\nDistance of node %d = %d", i, dist[i]);
            printf("\nPath = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while(j != scr);
        }
}
