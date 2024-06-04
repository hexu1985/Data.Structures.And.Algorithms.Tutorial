#include "linkedstack.hpp"
#include <iostream>

template <typename T>
using Stack = LinkedStack<T>;

void test_stack1() {
    Stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.isEmpty())
    {
        sum += mystack.peek();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
}

void test_stack2() {
    Stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

void test_stack3() {
    auto reportStackSize = 
        [](const Stack<int>& s) {
            std::cout << s.size() << " elements on stack\n";
        };

    auto reportStackTop =
        [](const Stack<int>& s) {
            std::cout << "Top element: " << s.peek() << '\n';
        };

    Stack<int> s;
    s.push(2);
    s.push(6);
    s.push(51);

    reportStackSize(s);
    reportStackTop(s);

    reportStackSize(s);
    s.pop();

    reportStackSize(s);
    reportStackTop(s);
}

void test_stack4() {
    Stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.isEmpty())
    {
        std::cout << ' ' << mystack.pop();
    }
    std::cout << '\n';
}

int main() {
    test_stack1();
    test_stack2();
    test_stack3();
    test_stack4();
}
