#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, two_sum_ii_input_array_is_sorted) {
    Solution solution;

    vector<int> numbers1 = {2, 7, 11, 15};
    vector<int> res1 = solution.twoSum(numbers1, 9);
    ASSERT_EQ(res1[0], 1);
    ASSERT_EQ(res1[1], 2);

    vector<int> numbers2 = {2, 3, 4};
    vector<int> res2 = solution.twoSum(numbers2, 6);
    ASSERT_EQ(res2[0], 1);
    ASSERT_EQ(res2[1], 3);

    vector<int> numbers3 = {-1, 0};
    vector<int> res3 = solution.twoSum(numbers3, -1);
    ASSERT_EQ(res3[0], 1);
    ASSERT_EQ(res3[1], 2);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}