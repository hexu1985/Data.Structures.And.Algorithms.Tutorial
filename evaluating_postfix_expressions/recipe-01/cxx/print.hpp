#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

inline void printHelper(const char* str) {
    std::cout << str;
}

inline void printHelper(const std::string& str) {
    std::cout << str;
}

inline void printHelper(std::string&& str) {
    std::cout << str;
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
