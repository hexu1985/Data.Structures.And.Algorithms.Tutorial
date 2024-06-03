#pragma once

#include <memory>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};
