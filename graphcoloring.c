#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

int n; // number of vertices
int m; // number of colors
int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix of the graph
int colors[MAX_VERTICES]; // colors assigned to vertices

bool is_safe(int v, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] && c == colors[i]) {
            return false;
        }
    }
    return true;
}

bool backtrack(int v) {
    int c;

    if (v == n) {
        // All vertices have been assigned a color
        return true;
    }

    for (c = 1; c <= m; c++) {
        if (is_safe(v, c)) {
            colors[v] = c;
            if (backtrack(v + 1)) {
                // A solution has been found
                return true;
            }
            colors[v] = 0; // backtrack
        }
    }

    // No solution found
    return false;
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (backtrack(0)) {
        printf("A solution exists:\n");
        for (i = 0; i < n; i++) {
            printf("Vertex %d: Color %d\n", i + 1, colors[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
