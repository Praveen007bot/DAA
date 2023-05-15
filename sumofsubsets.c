#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void backtrack(int set[], int n, int sum, int current_sum, bool used[], int start);

int main() {
    int n, i, sum;
    int set[MAX_SIZE];
    bool used[MAX_SIZE];

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        used[i] = false;
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    printf("All subsets that sum up to %d are:\n", sum);
    backtrack(set, n, sum, 0, used, 0);

    return 0;
}

void backtrack(int set[], int n, int sum, int current_sum, bool used[], int start) {
    int i;

    if (current_sum == sum) {
        // Print the current subset
        printf("{");
        for (i = 0; i < n; i++) {
            if (used[i]) {
                printf("%d ", set[i]);
            }
        }
        printf("}\n");
        return;
    }

    if (current_sum > sum) {
        return;
    }

    for (i = start; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current_sum += set[i];
            backtrack(set, n, sum, current_sum, used, i + 1);
            used[i] = false;
            current_sum -= set[i];
        }
    }
}
