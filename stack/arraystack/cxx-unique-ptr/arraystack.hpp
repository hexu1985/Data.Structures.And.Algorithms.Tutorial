#pragma once

#include <memory>

template <typename T>
class ArrayStack {
public:
    static constexpr size_t DEFAULT_CAPACITY = 10;

    ArrayStack(): _items{std::make_unique<T[]>(DEFAULT_CAPACITY)}, _capacity{DEFAULT_CAPACITY} {
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
        _items = std::make_unique<T>(DEFAULT_CAPACITY);
        _capacity = DEFAULT_CAPACITY;
        _size = 0;
    }

    void push(const T& item) {
        if (size() == capacity()) {
            extend();
        }
        _items[size()] = item;
        _size += 1;
    }

    void push(T&& item) {
        if (size() == capacity()) {
            extend();
        }
        _items[size()] = std::move(item);
        _size += 1;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("The stack is empty");
        }
        auto oldItem = _items[size() - 1];
        _size -= 1;
        if ((size() <= capacity()/4) &&
                (capacity() >= 2 * DEFAULT_CAPACITY)) {
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

    size_t capacity() const {
        return _capacity;
    }

private:
    void extend() {
        std::unique_ptr<T[]> temp = std::make_unique<T[]>(2*size());
        for (size_t i = 0; i < size(); i++) {
            temp[i] = std::move(_items[i]);
        }
        _items = std::move(temp);
        _capacity = 2*size();
    }

    void shrink() {
        std::unique_ptr<T[]> temp = std::make_unique<T[]>(capacity()/2);
        for (size_t i = 0; i < size(); i++) {
            temp[i] = std::move(_items[i]);
        }
        _items = std::move(temp);
        _capacity /= 2;
    }

private:
    std::unique_ptr<T[]> _items;
    size_t _capacity = 0;
    size_t _size = 0;
};
