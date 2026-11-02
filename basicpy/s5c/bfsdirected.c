#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for clock() and CLOCKS_PER_SEC

#define MAX_VERTICES 100

// First-principles array-based queue
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int vertices, edges, u, v, start_node;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};
    
    // Variables to track execution time
    clock_t start_time, end_time; 
    double cpu_time_used;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) (Note: use vertices from 0 to %d):\n", vertices - 1);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        // Bi-directional mapping for undirected graph
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adj[u][v] = 1;
            adj[v][u] = 1; 
        } else {
            printf("Invalid edge. Vertices must be between 0 and %d. Try again.\n", vertices - 1);
            i--; 
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start_node);

    if (start_node < 0 || start_node >= vertices) {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("BFS Traversal: ");
    
    // Start the clock right before the BFS logic begins
    start_time = clock();
    
    enqueue(start_node);
    visited[start_node] = 1;

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        // Check all potential neighbors in the adjacency matrix
        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    
    // Stop the clock immediately after the traversal completes
    end_time = clock();
    
    // Calculate the total time in seconds
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("\nExecution Time: %f seconds\n", cpu_time_used);

    return 0;
}