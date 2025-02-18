#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>
#include "random.hpp"
#include "bubble_sort.hpp"
#include "bubble_sort_with_tweak.hpp"
#include "sort_helper.hpp"

class TestSortingMethods: public testing::Test {
protected:
    virtual void SetUp()
    {
        for (int i=0; i < 100; i++) {
            lst_to_sort.push_back(randint(100, 999));
        }
        test_lst = lst_to_sort;
        std::sort(test_lst.begin(), test_lst.end());
    }

    virtual void TearDown()
    {
        print(test_lst);
    }
    
    std::vector<int> lst_to_sort;
    std::vector<int> test_lst;
};

TEST_F(TestSortingMethods, test_bubble_sort) {
    bubbleSort(lst_to_sort);
    EXPECT_EQ(lst_to_sort, test_lst);
}

TEST_F(TestSortingMethods, test_bubble_sort_with_tweak) {
    bubbleSortWithTweak(lst_to_sort);
    EXPECT_EQ(lst_to_sort, test_lst);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
