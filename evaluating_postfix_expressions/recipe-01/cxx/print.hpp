#pragma once

#include <iostream>
#include <string>

namespace std {

inline std::string to_string(std::string str) {
    return std::move(str);
}

}   // namespace std

template <typename T>
void print(T value) {
    std::cout << std::to_string(value) << '\n';
}

template <typename T, typename... Args>
void print(T value, Args... args) {
    std::cout << std::to_string(value) << ' ';
    print(args...);
}
