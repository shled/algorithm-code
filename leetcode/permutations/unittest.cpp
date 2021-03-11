#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, permutations) {
    Solution solution;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = solution.permute(nums);
    ASSERT_EQ(res.size(), 6);
    cout<<"nums: {1, 2, 3}"<<endl;
    for (auto item: res) {
        for (auto num: item) {
            cout<<num<<",";
        }
        cout<<endl;
    }

    nums = {0, 1};
    res = solution.permute(nums);
    ASSERT_EQ(res.size(), 2);
    cout<<"nums: {0, 1}"<<endl;
    for (auto item: res) {
        for (auto num: item) {
            cout<<num<<",";
        }
        cout<<endl;
    }

    nums = {1};
    res = solution.permute(nums);
    ASSERT_EQ(res.size(), 1);
    cout<<"nums: {1}"<<endl;
    for (auto item: res) {
        for (auto num: item) {
            cout<<num<<",";
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
