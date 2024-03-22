#include <iostream>
#include "converter.hpp"
#include "input.hpp"
#include "print.hpp"

int main() {
    while (true) {
        auto sourceStr = input("Enter a infix expression: ");
        if (sourceStr == "") {
            break;
        } else {
            IFToPFConverter converter{Scanner(sourceStr)};
            auto postfix = converter.convert();
            print_without_ln("Postfix:", ' ');
            for (const auto& token : postfix) {
                print_without_ln(token, ' ');
            }
            print("");
        } 
    }
}
