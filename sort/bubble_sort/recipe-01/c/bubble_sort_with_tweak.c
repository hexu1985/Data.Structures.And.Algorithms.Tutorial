#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* lyst, int i, int j) {
    int temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

void bubble_sort_with_tweak(int* lyst, int n) {
    int i;
    bool swapped;
    while (n > 1) {
        swapped = false;
        i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                swap(lyst, i, i - 1);
                swapped = true;
            }
            i += 1;
        }
        if (!swapped) return;
        n -= 1;
    }
}

void print(int* lyst, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lyst[i]);
    }
    printf("]\n");
}

int* range(int n) {
    int* arr = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    int lyst[] = {2, 4, 3, 0, 1, 5};
    int n = sizeof(lyst)/sizeof(lyst[0]);
    bubble_sort_with_tweak(lyst, n);
    print(lyst, n);

    n = 6;
    int* lyst1 = range(n);
    bubble_sort_with_tweak(lyst1, n);
    print(lyst1, n);

    return 0;
}
