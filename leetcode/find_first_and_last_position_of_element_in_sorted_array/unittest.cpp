#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, find_first_and_last_position_of_element_in_sorted_array) {
    Solution solution;

    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> ret1 = solution.searchRange(nums1, 8);
    EXPECT_EQ(ret1[0], 3);
    EXPECT_EQ(ret1[1], 4);

    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> ret2 = solution.searchRange(nums2, 6);
    EXPECT_EQ(ret2[0], -1);
    EXPECT_EQ(ret2[1], -1);

    vector<int> nums3 = {};
    vector<int> ret3 = solution.searchRange(nums3, 0);
    EXPECT_EQ(ret3[0], -1);
    EXPECT_EQ(ret3[1], -1);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
