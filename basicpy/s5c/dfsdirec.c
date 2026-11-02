#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VERTICES 100
int adj[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
int vertices;
void DFS(int current) {
    printf("%d ", current);
    visited[current] = 1;

    for (int i = 0; i < vertices; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start_node;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the directed edges (u v) (Note: use vertices from 0 to %d):\n", vertices - 1);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adj[u][v] = 1; 
        } else {
            printf("Invalid edge. Vertices must be between 0 and %d. Try again.\n", vertices - 1);
            i--; 
        }
    }
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start_node);
    if (start_node < 0 || start_node >= vertices) {
        printf("Invalid starting vertex.\n");
        return 1;
    }
    printf("DFS Traversal: ");
    DFS(start_node);
    printf("\n");
    return 0;
}