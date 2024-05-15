#include "arrays.hpp"
#include <iostream>

template <typename T>
std::ostream& operator<< (std::ostream& out, const Array<T>& arr) {
    out << "[";
    out << arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        out << ", " << arr[i];
    }
    out << "]";
    return out;
}

void test_array1() {
    Array<int> myints(5);
    std::cout << "size of myints: " << myints.size() << std::endl;
}

void test_array2() {
    Array<int> myarray(10);
    unsigned int i;

    // assign some values:
    for (i=0; i<10; i++) myarray[i]=i;

    // print content
    std::cout << "myarray contains: " << myarray << std::endl;
    for (i=0; i<10; i++)
        std::cout << myarray[i] << ' ';
    std::cout << '\n';
}

void test_array3() {
    Array<int> myarray = { 2, 16, 77, 34, 50 };

    std::cout << "myarray contains: " << myarray << std::endl;
    for (auto val : myarray) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
}

int main() {
    test_array1();
    test_array2();
    test_array3();
}
