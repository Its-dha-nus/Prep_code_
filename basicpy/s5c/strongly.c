#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

// Global variables for the original graph, transposed graph, and traversal tracking
int adj[MAX_VERTICES][MAX_VERTICES] = {0};
int transposed_adj[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};

// Stack for tracking node finishing times
int stack[MAX_VERTICES];
int top = -1;

// First DFS: Explores the original graph and pushes nodes to the stack upon finishing
void DFS1(int current, int vertices) {
    visited[current] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            DFS1(i, vertices);
        }
    }
    // Push to stack only after all outgoing paths are exhausted
    stack[++top] = current;
}

// Second DFS: Explores the reversed graph to map out the isolated components
void DFS2(int current, int vertices) {
    printf("%d ", current);
    visited[current] = 1;
    for (int i = 0; i < vertices; i++) {
        if (transposed_adj[current][i] == 1 && !visited[i]) {
            DFS2(i, vertices);
        }
    }
}

int main() {
    int vertices, edges, u, v;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of directed edges: ");
    scanf("%d", &edges);

    printf("Enter the directed edges (u v) (Note: use vertices from 0 to %d):\n", vertices - 1);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adj[u][v] = 1;                 // Map original directed edge
            transposed_adj[v][u] = 1;      // Map reversed edge directly for Step 2
        } else {
            printf("Invalid edge. Vertices must be between 0 and %d. Try again.\n", vertices - 1);
            i--; 
        }
    }

    // Start the clock immediately before the algorithmic logic
    start_time = clock();

    // Step 1: Run DFS on the original graph to fill the stack based on finishing times
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS1(i, vertices);
        }
    }

    // Reset the visited array so the second DFS pass can use it
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("\nStrongly Connected Components:\n");

    // Step 2 & 3: Pop nodes from the stack and run DFS on the reversed graph
    while (top != -1) {
        int current = stack[top--];
        
        // If the popped node hasn't been visited in this second pass, it forms a new SCC
        if (!visited[current]) {
            printf("[ ");
            DFS2(current, vertices);
            printf("]\n");
        }
    }

    // Stop the clock
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    
    printf("\nExecution Time: %f seconds\n", cpu_time_used);

    return 0;
}