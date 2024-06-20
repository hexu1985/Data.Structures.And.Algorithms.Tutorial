#include "arrayqueue.hpp"
#include <iostream>

template <typename T>
using Queue = ArrayQueue<T>;

void test_queue1() {
    Queue<int> myqueue;
    int sum (0);

    for (int i=1;i<=10;i++) myqueue.add(i);

    while (!myqueue.isEmpty())
    {
        sum += myqueue.pop();
    }

    std::cout << "total: " << sum << '\n';
}

void test_queue2() {
    Queue<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.add(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

int main() {
    test_queue1();
    test_queue2();
}
