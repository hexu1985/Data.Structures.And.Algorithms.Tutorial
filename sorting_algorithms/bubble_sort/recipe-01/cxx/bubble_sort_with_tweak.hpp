#pragma once

#include <utility>

template <typename Container>
void bubbleSortWithTweak(Container& lyst) {
    int n = lyst.size();
    while (n > 1) {
        bool swapped = false;
        int i = 1;
        while (i < n) {
            if (lyst[i] < lyst[i - 1]) {
                std::swap(lyst[i], lyst[i-1]);
                swapped = true;
            }
            i += 1;
        }
        if (!swapped) return;
        n -= 1;
    }
}

