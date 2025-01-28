#include <gtest/gtest.h>
#include <iostream>
#include "linkedstack.hpp"

template <typename T>
using Stack = LinkedStack<T>;

class TestStackMethods: public testing::Test {
protected:
    virtual void SetUp()
    {
//        std::cout << "TestStackMethods SetUp" << std::endl;
    }

    virtual void TearDown()
    {
//        std::cout << "TestStackMethods TearDown" << std::endl;
    }

    Stack<int> stack;
};

TEST_F(TestStackMethods, test_is_empty) {
    EXPECT_TRUE(stack.isEmpty());
    stack.push(42);
    EXPECT_FALSE(stack.isEmpty());
}

TEST_F(TestStackMethods, test_size) {
    EXPECT_EQ(stack.size(), 0);
    stack.push(42);
    EXPECT_EQ(stack.size(), 1);
}

TEST_F(TestStackMethods, test_push) {
    stack.push(42);
    EXPECT_EQ(stack.size(), 1);
}

TEST_F(TestStackMethods, test_pop) {
    stack.push(42);
    EXPECT_EQ(stack.pop(), 42);
    EXPECT_TRUE(stack.isEmpty());
}

TEST_F(TestStackMethods, test_peek) {
    stack.push(42);
    EXPECT_EQ(stack.peek(), 42);
    EXPECT_EQ(stack.size(), 1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

