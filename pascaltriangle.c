#include <stdio.h>

int main()
{
    int n, i, j, coef = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || i == 0) {
                coef = 1;  // set the coefficient to 1 for the first column and row
            } else {
                coef = coef * (i - j + 1) / j;  // calculate the coefficient for other cells
            }
            printf("%d ", coef);  // print the coefficient
        }
        printf("\n");  // move to the next line
    }

    return 0;
}
