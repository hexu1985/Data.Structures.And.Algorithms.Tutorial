#include "sort_helper.h"

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
