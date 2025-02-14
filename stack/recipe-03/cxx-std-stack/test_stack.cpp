#include <gtest/gtest.h>
#include <iostream>
#include <stack>

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

    std::stack<int> stack;
};

TEST_F(TestStackMethods, test_is_empty) {
    EXPECT_TRUE(stack.empty());
    stack.push(42);
    EXPECT_FALSE(stack.empty());
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
    EXPECT_EQ(stack.top(), 42);
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST_F(TestStackMethods, test_peek) {
    stack.push(42);
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

