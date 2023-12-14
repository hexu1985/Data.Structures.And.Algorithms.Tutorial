#include "tokens.hpp"
#include "print.hpp"

int main() {
    // A simple tester program
    auto plus = Token('+');
    auto minus = Token('-');
    auto mul = Token('*');
    auto div = Token('/');
    auto unknown = Token('#');
    auto anInt = Token(34);
    print(plus, minus, mul, div, unknown, anInt);
}
