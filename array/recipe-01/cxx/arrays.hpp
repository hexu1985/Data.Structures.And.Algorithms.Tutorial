#pragma once

#include <vector>

template <typename T>
class Array {
public:
    Array(int capacity, const T& fillValue = T()) {
        for (int count = 0; count < capacity; count++) {
            _items.push_back(fillValue);
        }
    }

    Array(std::initializer_list<T> il): _items(il) {}

    size_t size() const { return _items.size(); }

    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    iterator begin() { return _items.begin(); }
    const_iterator begin() const { return _items.begin(); }

    iterator end() { return _items.end(); }
    const_iterator end() const { return _items.end(); }

    T& operator[] (size_t n) { return _items[n]; }
    const T& operator[] (size_t n) const { return _items[n]; }

private:
    std::vector<T> _items;
};
