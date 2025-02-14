#pragma once

#include <list>

template <typename T>
class Queue {
public:
    Queue() = default;

    bool is_empty() const {
        return _items.empty();
    }

    void enqueue(const T& item) {
        _items.push_back(item);
    }

    T dequeue() {
        auto item = _items.front();
        _items.pop_front();
        return item;
    }

    size_t size() {
        return _items.size();
    }

private:
    std::list<T> _items;
};
