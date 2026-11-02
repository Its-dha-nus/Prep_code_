#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int adj[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
int vertices;
int stack[MAX_VERTICES];
int top = -1;
void DFS(int current) {
    visited[current] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
        stack[++top] = current;
}

int main() {
    int edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of directed edges: ");
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
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }
    printf("Topological Sort: ");
        while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}