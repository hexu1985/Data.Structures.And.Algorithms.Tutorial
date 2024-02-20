#include "scanner.hpp"
#include "print.hpp"
#include "input.hpp"

int main() {
    // A simple tester program
    while (true) {
        auto sourceStr = input("Enter an expression: ");
        if (sourceStr == "") break;
        Scanner scanner{sourceStr};
        while (scanner.hasNext())
            print(scanner.next());
    }
}
