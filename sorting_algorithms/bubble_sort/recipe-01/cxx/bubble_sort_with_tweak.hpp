#pragma once

template <typename Container>
void swap(Container& lyst, int i, int j) {
    auto temp = lyst[i];
    lyst[i] = lyst[j];
    lyst[j] = temp;
}

template <typename Container>
void bubble_sort(Container& lyst) {
    int n = lyst.size();
    while (n > 1) {
        bool swapped = false;
        int i = 1;
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

