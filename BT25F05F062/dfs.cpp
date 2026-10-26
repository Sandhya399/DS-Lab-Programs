#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX] = {0};
int n;

// DFS function
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v, start;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Undirected graph
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Perform DFS
    printf("DFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}