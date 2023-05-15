#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            printf("  ");  // print two spaces for each missing number
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", j);  // print the numbers from 1 to i
        }
        printf("\n");  // move to the next line
    }

    return 0;
}
