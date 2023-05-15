#include <stdio.h>

int main() {
    int num, sum, i;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    sum = 0;

    // Find proper divisors and sum them up
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if the number is perfect
    if (sum == num) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}
