# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(evaluating_postfix_expressions LANGUAGES CXX)

# require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/BigNumber)

add_executable(tokens_test 
    tokens.hpp
    print.hpp
    tokens_test.cpp)
target_include_directories(tokens_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber/src)
target_link_libraries(tokens_test PRIVATE BigNumber)

add_executable(scanner_test 
    tokens.hpp
    scanner.hpp
    print.hpp
    input.hpp
    scanner_test.cpp)
target_include_directories(scanner_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber/src)
target_link_libraries(scanner_test PRIVATE BigNumber)

add_executable(evaluatorapp 
    tokens.hpp
    scanner.hpp
    model.hpp
    print.hpp
    input.hpp
    evaluatorapp.cpp)
target_include_directories(evaluatorapp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber/src)
target_link_libraries(evaluatorapp PRIVATE BigNumber)

add_executable(converter_test 
    tokens.hpp
    scanner.hpp
    print.hpp
    input.hpp
    converter.hpp
    converter_test.cpp)
target_include_directories(converter_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/BigNumber/src)
target_link_libraries(converter_test PRIVATE BigNumber)

