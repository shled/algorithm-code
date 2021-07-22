#include "gtest/gtest.h"

#include "solution.h"

#include <iostream>

TEST(LEETCODE, kth_largest_element_in_an_array) {
    Solution solution;

    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> ret1 = solution.topKFrequent(nums1, 2);
    for (auto& v: ret1) {cout<<v<<",";} cout<<endl;

    vector<int> nums2 = {1};
    vector<int> ret2 = solution.topKFrequent(nums2, 1);
    for (auto& v: ret2) {cout<<v<<",";} cout<<endl;
}

int main(int argc, char* argv[]){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
