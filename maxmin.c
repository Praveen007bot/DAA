#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minmax, left, right;
    int mid;

    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid+1, high);

    if (left.min < right.min) {
        minmax.min = left.min;
    } else {
        minmax.min = right.min;
    }

    if (left.max > right.max) {
        minmax.max = left.max;
    } else {
        minmax.max = right.max;
    }

    return minmax;
}

int main() {
    int arr[] = {2, 5, 1, 8, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair minmax = getMinMax(arr, 0, n-1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
