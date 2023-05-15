#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sum(int freq[], int i, int j) {
    int k, s = 0;
    for (k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];
    int i, j, k, L, r;

    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L + 1; i++) {
            j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (k = i; k <= j; k++) {
                r = ((k > i) ? cost[i][k - 1] : 0) +
                    ((k < j) ? cost[k + 1][j] : 0) +
                    sum(freq, i, j);
                if (r < cost[i][j])
                    cost[i][j] = r;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Cost of optimal BST is %d", optimalSearchTree(keys, freq, n));
    return 0;
}
