#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, open_the_lock) {
    Solution solution;

    vector<string> deadends1 = {"0201", "0101", "0102", "1212", "2002"};
    ASSERT_EQ(solution.openLock(deadends1, "0202"), 6);
    vector<string> deadends2 = {"8888"};
    ASSERT_EQ(solution.openLock(deadends2, "0009"), 1);
    vector<string> deadends3 = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    ASSERT_EQ(solution.openLock(deadends3, "8888"), -1);
    vector<string> deadends4 = {"0000"};
    ASSERT_EQ(solution.openLock(deadends4, "8888"), -1);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}