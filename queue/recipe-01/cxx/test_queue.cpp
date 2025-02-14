#include <gtest/gtest.h>
#include <iostream>
#include "arrayqueue.hpp"

template <typename T>
using Queue = ArrayQueue<T>;

class TestQueueMethods: public testing::Test {
protected:
    virtual void SetUp()
    {
//        std::cout << "TestQueueMethods SetUp" << std::endl;
    }

    virtual void TearDown()
    {
//        std::cout << "TestQueueMethods TearDown" << std::endl;
    }

    Queue<int> queue;
};

TEST_F(TestQueueMethods, test_is_empty) {
    EXPECT_TRUE(queue.isEmpty());
    queue.add(42);
    EXPECT_FALSE(queue.isEmpty());
}

TEST_F(TestQueueMethods, test_size) {
    EXPECT_EQ(queue.size(), 0);
    queue.add(42);
    EXPECT_EQ(queue.size(), 1);
}

TEST_F(TestQueueMethods, test_enqueue) {
    queue.add(42);
    EXPECT_EQ(queue.size(), 1);
}

TEST_F(TestQueueMethods, test_dequeue) {
    queue.add(42);
    EXPECT_EQ(queue.pop(), 42);
    EXPECT_TRUE(queue.isEmpty());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

