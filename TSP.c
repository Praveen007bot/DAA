#include <stdio.h>
#include <limits.h>

#define N 4

int tsp(int graph[][N], int visited[], int curr)
{
    int i, j, min_cost = INT_MAX, cost;

    // Base case: all cities have been visited
    if (curr == N) {
        return graph[visited[curr-1]][visited[0]];
    }

    // Recursively try every unvisited city as the next stop
    for (i = curr; i < N; i++) {
        if (i == curr || visited[i] != visited[curr]) {
            int temp = visited[i];
            visited[i] = visited[curr];
            visited[curr] = temp;

            cost = graph[visited[curr-1]][visited[curr]] + tsp(graph, visited, curr+1);

            temp = visited[i];
            visited[i] = visited[curr];
            visited[curr] = temp;

            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }

    return min_cost;
}

int main()
{
    int graph[N][N] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
    int visited[N], i;

    // Initialize visited array with all cities unvisited
    for (i = 0; i < N; i++) {
        visited[i] = i;
    }

    printf("The minimum cost of the TSP is %d\n", tsp(graph, visited, 1));
    return 0;
}
