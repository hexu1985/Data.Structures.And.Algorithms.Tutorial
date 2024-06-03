#pragma once

#include "node.hpp"

template <typename T>
class LinkedStack {
public:
    LinkedStack() {}

    LinkedStack(const LinkedStack&) = delete;
    LinkedStack& operator= (const LinkedStack&) = delete;

    ~LinkedStack() {
        clear();
    }

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
        while (_items != nullptr) {
            Node<T>* node = _items;
            _items = node->next;
            delete node;
        }
        _items = nullptr;
    }

    void push(const T& item) {
        Node<T>* new_node = new Node<T>{};
        new_node->data = item;
        new_node->next = _items;
        _items = new_node;
        _size += 1;
    }

    void push(T&& item) {
        Node<T>* new_node = new Node<T>{};
        new_node->data = std::move(item);
        new_node->next = _items;
        _items = new_node;
        _size += 1;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        T data{std::move(_items->data)};
        Node<T>* node = _items;
        _items = _items->next;
        _size -= 1;
        delete node;
        return data;
    }

    size_t size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

private:
    Node<T>* _items = nullptr;
    size_t _size = 0;
};
