#include <array>
#include <iostream>

template <typename T, size_t N>
std::ostream& operator<< (std::ostream& out, const std::array<T, N>& arr) {
    out << "[";
    out << arr[0];
    for (size_t i = 1; i < N; i++) {
        out << ", " << arr[i];
    }
    out << "]";
    return out;
}

void test_array1() {
    std::array<int,5> myints;
    std::cout << "size of myints: " << myints.size() << std::endl;
}

void test_array2() {
    std::array<int,10> myarray;
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
    std::array<int,5> myarray = { 2, 16, 77, 34, 50 };

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
