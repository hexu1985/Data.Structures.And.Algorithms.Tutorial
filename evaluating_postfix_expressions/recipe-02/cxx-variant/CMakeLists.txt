# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(evaluating_postfix_expressions LANGUAGES CXX)

# require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

add_executable(evaluatorapp 
    tokens.hpp
    scanner.hpp
    model.hpp
    print.hpp
    input.hpp
    evaluatorapp.cpp)
