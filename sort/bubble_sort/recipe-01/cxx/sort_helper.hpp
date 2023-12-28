#pragma once

#include <iostream>
#include <numeric>

template <typename Container>
void print(Container& lyst) {
    std::cout << "[ ";
    for (const auto& item : lyst) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

template <typename Container>
void range(Container& arr, int n) {
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}


