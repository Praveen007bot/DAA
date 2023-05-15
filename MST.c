#include <stdio.h>
#include <stdbool.h>

#define INF 999999
#define MAX 100

int graph[MAX][MAX];
int n;

int minKey(int key[], bool mstSet[]) {
    int i, min = INF, min_index;
    for (i = 0; i < n; i++) {
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void primMST() {
    int parent[MAX], key[MAX], i, j, k;
    bool mstSet[MAX];

    for (i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (i = 0; i < n - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (j = 0; j < n; j++) {
            if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST();

    return 0;
}
