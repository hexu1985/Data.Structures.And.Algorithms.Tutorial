#include <stdio.h>
#include <stdlib.h>

void swap(int* lyst, int i, int j) {
    int temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

void bubble_sort(int* lyst, int n) {
    int i;
    while (n > 1) {
        i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                swap(lyst, i, i - 1);
            }
            i += 1;
        }
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
    bubble_sort(lyst, n);
    print(lyst, n);

    n = 6;
    int* lyst1 = range(n);
    bubble_sort(lyst1, n);
    print(lyst1, n);
}
