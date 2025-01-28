#pragma once

#include <vector>

template <typename T>
class Stack {
public:
    Stack() = default;

    bool is_empty() {
        return _items.empty();
    }

    void push(const T& item) {
        _items.push_back(item);
    }

    T pop() {
        auto item = _items.back();
        _items.pop_back();
        return item;
    }

    const T& peek() const {
        return _items.back();
    }

    T& peek() {
        return _items.back();
    }

    size_t size() const {
        return _items.size();
    }

private:
    std::vector<T> _items;
};
