#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, coin_change) {
    Solution solution;

    vector<int> coins = {1, 2, 5};
    ASSERT_EQ(solution.coinChange(coins, 11), 3);
    coins = {2};
    ASSERT_EQ(solution.coinChange(coins, 3), -1);
    coins = {1};
    ASSERT_EQ(solution.coinChange(coins, 0), 0);
    ASSERT_EQ(solution.coinChange(coins, 1), 1);
    ASSERT_EQ(solution.coinChange(coins, 2), 2);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
