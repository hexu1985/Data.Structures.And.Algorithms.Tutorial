#pragma once

#include "node.hpp"

template <typename T>
class LinkedStack {
public:
    LinkedStack() {}

    const T& peek() const {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        return _items->data;
    }

    T& peek() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        return _items->data;
    }

    void clear() {
        _size = 0;
        _items.reset();
    }

    void push(const T& item) {
        std::unique_ptr<Node<T>> new_node = std::make_unique<Node<T>>();
        new_node->data = item;
        new_node->next = std::move(_items);
        _items = std::move(new_node);
        _size += 1;
    }

    void push(T&& item) {
        std::unique_ptr<Node<T>> new_node = std::make_unique<Node<T>>();
        new_node->data = std::move(item);
        new_node->next = std::move(_items);
        _items = std::move(new_node);
        _size += 1;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        T data{std::move(_items->data)};
        _items = std::move(_items->next);
        _size -= 1;
        return data;
    }

    size_t size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

private:
    std::unique_ptr<Node<T>> _items;
    size_t _size = 0;
};
