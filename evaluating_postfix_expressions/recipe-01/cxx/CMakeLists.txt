# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(evaluating_postfix_expressions LANGUAGES CXX)

add_executable(tokens_test 
    tokens.hpp
    print.hpp
    tokens_test.cpp)

add_executable(scanner_test 
    tokens.hpp
    scanner.hpp
    print.hpp
    input.hpp
    scanner_test.cpp)
