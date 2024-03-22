#pragma once

#include <string>
#include <iostream>

std::string input(const std::string& prompt) {
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);
    return line;
}
