#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, kth_largest_element_in_an_array) {
    Solution solution;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    EXPECT_EQ(solution.findKthLargest(nums1, 2), 5);
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    EXPECT_EQ(solution.findKthLargest(nums2, 4), 4);
    vector<int> nums3 = {1};
    EXPECT_EQ(solution.findKthLargest(nums3, 1), 1);
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
