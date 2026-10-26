#include <stdio.h>

#define MAX 100

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int n, edges;
    int u, v, start;
    int front = 0, rear = 0;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

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

    // BFS traversal
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");

    return 0;
}