#include <queue>
#include <iostream>

void test_queue1() {
    std::queue<int> myqueue;
    int sum (0);

    for (int i=1;i<=10;i++) myqueue.push(i);

    while (!myqueue.empty())
    {
        sum += myqueue.front();
        myqueue.pop();
    }

    std::cout << "total: " << sum << '\n';
}

void test_queue2() {
    std::queue<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

int main() {
    test_queue1();
}
