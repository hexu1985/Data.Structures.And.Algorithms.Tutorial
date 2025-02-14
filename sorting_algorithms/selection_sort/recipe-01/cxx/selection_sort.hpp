#pragma once

template <typename Container>
void swap(Container& lyst, int i, int j) {
    auto temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

template <typename Container>
void selection_sort(Container& lyst) {
    int i = 0;
    int n = lyst.size();
    while (i < n - 1) {
        int minIndex = i;
        int j = i + 1;
        while (j < n) {
            if (lyst[j] < lyst[minIndex]) {
                minIndex = j;
            }
            j += 1;
        }
        if (minIndex != i) {
            swap(lyst, minIndex, i);
        }
        i += 1;
    }
}

