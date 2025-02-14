#pragma once

#include <memory>

template <typename T>
class Array {
public:
    Array(size_t capacity, const T& fillValue = T()): _items(new T[capacity]), _capacity(capacity) {
        for (size_t count = 0; count < capacity; count++) {
            _items[count] = fillValue;
        }
    }

    Array(std::initializer_list<T> il): _items(new T[il.size()]), _capacity(il.size()) {
        size_t count = 0;
        for (auto& item : il) {
            _items[count] = item;
            count += 1;
        }
    }

    size_t size() const { return _capacity; }

    T* begin() { return &_items[0]; }
    const T* begin() const { return &_items[0]; }

    T* end() { return &_items[_capacity-1]; }
    const T* end() const { return &_items[_capacity-1]; }

    T& operator[] (size_t n) { return _items[n]; }
    const T& operator[] (size_t n) const { return _items[n]; }

private:
    std::unique_ptr<T[]> _items;
    size_t _capacity;
};
