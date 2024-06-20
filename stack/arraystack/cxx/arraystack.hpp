#pragma once

#include "arrays.hpp"

template <typename T>
class ArrayStack {
public:
    static constexpr size_t DEFAULT_CAPACITY = 10;

    ArrayStack(): _items(DEFAULT_CAPACITY), _size(0) {
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        return _items[size()-1];
    }

    T& peek() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        return _items[size()-1];
    }

    void clear() {
        _size = 0;
        _items = Array<T>(DEFAULT_CAPACITY);
    }

    void push(const T& item) {
        if (size() == _items.size()) {
            expand();
        }
        _items[size()] = item;
        _size += 1;
    }

    void push(T&& item) {
        if (size() == _items.size()) {
            expand();
        }
        _items[size()] = std::move(item);
        _size += 1;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        auto oldItem = std::move(_items[size() - 1]);
        _size -= 1;
        if ((size() <= _items.size()/4) &&
                (_items.size() >= 2 * DEFAULT_CAPACITY)) {
            shrink();
        }
        return oldItem;
    }

    size_t size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

private:
    void expand() {
        Array<T> temp(2*size());
        for (size_t i = 0; i < size(); i++) {
            temp[i] = std::move(_items[i]);
        }
        _items = std::move(temp);
    }

    void shrink() {
        Array<T> temp(_items.size()/2);
        for (size_t i = 0; i < size(); i++) {
            temp[i] = std::move(_items[i]);
        }
        _items = std::move(temp);
    }

private:
    Array<T> _items;
    size_t _size = 0;
};
