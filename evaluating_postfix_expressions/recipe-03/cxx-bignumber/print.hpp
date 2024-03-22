#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "bignumber.h"

inline void printHelper(char c) {
    std::cout << c;
}

inline void printHelper(const char* str) {
    std::cout << str;
}

inline void printHelper(const std::string& str) {
    std::cout << str;
}

inline void printHelper(std::string&& str) {
    std::cout << str;
}

inline void printHelper(const BigNumber& i) {
    std::cout << i;
}

inline void printHelper(BigNumber&& i) {
    std::cout << i;
}

inline void printHelper(const std::exception& e) {
    std::cout << e.what(); 
}

template <typename T>
void printHelper(T&& value) {
    std::cout << std::to_string(std::forward<T>(value)); 
}

template <typename T, typename... Args>
void printHelper(T&& value, Args&&... args) {
    printHelper(std::forward<T>(value));
    printHelper(" ");
    printHelper(std::forward<Args>(args)...);
}

template <typename... Args>
void print(Args&&... args) {
    printHelper(std::forward<Args>(args)...);
    printHelper("\n");
}

template <typename... Args>
void print_without_ln(Args&&... args) {
    printHelper(std::forward<Args>(args)...);
}
