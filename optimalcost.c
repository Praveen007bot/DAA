#include <stdio.h>
#include <limits.h>

#define V 5  // number of vertices in the graph

int minDistance(int dist[], int visited[]) {
    // find the vertex with the minimum distance value
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];  // array to store the shortest distance from start to each vertex
    int visited[V];  // array to keep track of visited vertices

    // initialize the distance and visited arrays
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;

    // find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print the shortest distance from start to each vertex
    printf("Vertex\tDistance from start\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {{0, 10, 20, 0, 0},
                       {10, 0, 5, 15, 0},
                       {20, 5, 0, 30, 10},
                       {0, 15, 30, 0, 20},
                       {0, 0, 10, 20, 0}};
    int start = 0;  // start vertex

    dijkstra(graph, start);

    return 0;
}
