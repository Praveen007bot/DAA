#include <stdio.h>
#include <limits.h>

#define N 4

void floyd(int graph[][N])
{
    int dist[N][N], i, j, k;

    // Initialize dist matrix with the edge weights
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Find the shortest path between every pair of vertices
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path between every pair of vertices
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d   ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int graph[N][N] = {{0, 5, INT_MAX, 10},
                       {INT_MAX, 0, 3, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 1},
                       {INT_MAX, INT_MAX, INT_MAX, 0}};

    floyd(graph);

    return 0;
}
