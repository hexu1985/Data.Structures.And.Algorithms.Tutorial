#include <stack>
#include <iostream>

void test_stack1() {
    std::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
}

void test_stack2() {
    std::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

void test_stack3() {
    auto reportStackSize = 
        [](const std::stack<int>& s) {
            std::cout << s.size() << " elements on stack\n";
        };

    auto reportStackTop =
        [](const std::stack<int>& s) {
            std::cout << "Top element: " << s.top() << '\n';
        };

    std::stack<int> s;
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
    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
}

int main() {
    test_stack1();
    test_stack2();
    test_stack3();
    test_stack4();
}
