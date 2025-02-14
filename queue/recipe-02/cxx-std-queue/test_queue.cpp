#include <gtest/gtest.h>
#include <iostream>
#include <queue>

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

    std::queue<int> queue;
};

TEST_F(TestQueueMethods, test_is_empty) {
    EXPECT_TRUE(queue.empty());
    queue.push(42);
    EXPECT_FALSE(queue.empty());
}

TEST_F(TestQueueMethods, test_size) {
    EXPECT_EQ(queue.size(), 0);
    queue.push(42);
    EXPECT_EQ(queue.size(), 1);
}

TEST_F(TestQueueMethods, test_enqueue) {
    queue.push(42);
    EXPECT_EQ(queue.size(), 1);
}

TEST_F(TestQueueMethods, test_dequeue) {
    queue.push(42);
    queue.push(43);
    EXPECT_EQ(queue.front(), 42);
    queue.pop();
    queue.pop();
    EXPECT_TRUE(queue.empty());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

