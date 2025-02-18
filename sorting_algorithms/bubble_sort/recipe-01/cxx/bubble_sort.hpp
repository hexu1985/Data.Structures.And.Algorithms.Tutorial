#pragma once

#include <utility>

template <typename Container>
void bubbleSort(Container& lyst) {
    int n = lyst.size();
    while (n > 1) {
        int i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                std::swap(lyst[i], lyst[i-1]);
            }
            i += 1;
        }
        n -= 1;
    }
}

