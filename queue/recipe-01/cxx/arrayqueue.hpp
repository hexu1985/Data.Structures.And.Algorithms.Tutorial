#pragma once

#include "arrays.hpp"

template <typename T>
class ArrayQueue {
public:
    static constexpr size_t DEFAULT_CAPACITY = 10;

    ArrayQueue(): _items(DEFAULT_CAPACITY), _size(0), _front(-1), _rear(-1) {
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return _items[_front];
    }

    T& peek() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return _items[_front];
    }

    void clear() {
        _size = 0;
        _front = _rear = -1;
        _items = Array<T>(DEFAULT_CAPACITY);
    }

    void add(const T& item) {
        if (size() == _items.size()) {
            expand();
        }
        if (isEmpty()) {
            _front = _rear = 0;
        } else if (_rear == _items.size() - 1) {
            _rear = 0;
        } else {
            _rear += 1;
        }
        _items[_rear] = item;
        _size += 1;
    }

    void add(T&& item) {
        if (size() == _items.size()) {
            expand();
        }
        if (isEmpty()) {
            _front = _rear = 0;
        } else if (_rear == _items.size() - 1) {
            _rear = 0;
        } else {
            _rear += 1;
        }
        _items[_rear] = std::move(item);
        _size += 1;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        auto data = std::move(_items[_front]);
        _size -= 1;
        if (isEmpty()) {
            _front = _rear = -1;
        } else if (_front == _items.size() - 1) {
            _front = 0;
        } else {
            _front += 1;
        }
        if ((size() <= .25 * _items.size()) &&
                (DEFAULT_CAPACITY <= _items.size() / 2)) {
            shrink();
        }
        return data;
    }

    size_t size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

private:
    void expand() {
        Array<T> tempArray(2*_items.size());
        int i = 0;
        int cursor = _front;
        while (cursor != _rear) {
            tempArray[i] = std::move(_items[cursor]);
            if (cursor == _items.size() - 1) {
                cursor = 0;
            } else {
                cursor += 1;
            }
            i += 1;
        }
        _items = std::move(tempArray);
        if (!isEmpty()) {
            _front = 0;
            _rear = size() - 1;
        }
    }

    void shrink() {
        Array<T> tempArray(_items.size()/2);
        int i = 0;
        int cursor = _front;
        while (cursor != _rear) {
            tempArray[i] = std::move(_items[cursor]);
            if (cursor == _items.size() - 1) {
                cursor = 0;
            } else {
                cursor += 1;
            }
            i += 1;
        }
        _items = std::move(tempArray);
        if (!isEmpty()) {
            _front = 0;
            _rear = size() - 1;
        }
    }

private:
    Array<T> _items;
    size_t _size = 0;
    int _front = -1;
    int _rear = -1;
};
