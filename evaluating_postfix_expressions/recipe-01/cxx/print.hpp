#pragma once

#include <iostream>

template <typename T>
void print(T value) {
    std::cout << std::to_string(value) << '\n';
}

template <typename T, typename... Args>
void print(T value, Args... args) {
    std::cout << std::to_string(value) << ' ';
    print(args...);
}
