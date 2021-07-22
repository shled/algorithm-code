#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, binary_search) {
    Solution solution;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(solution.search(nums, 9), 4);
    EXPECT_EQ(solution.search(nums, 2), -1);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}