#include "tokens.hpp"
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

int main() {
    // A simple tester program
    auto plus = Token('+');
    auto minus = Token('-');
    auto mul = Token('*');
    auto div = Token('/');
    auto unknown = Token('#');
    auto anInt = Token(34);
    print(plus, minus, mul, div, unknown, anInt);
}
