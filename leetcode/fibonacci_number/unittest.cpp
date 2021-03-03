#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, fibonacci_number) {
    Solution solution;
    ASSERT_EQ(solution.fib(0), 0);
    ASSERT_EQ(solution.fib(1), 1);
    ASSERT_EQ(solution.fib(2), 1);
    ASSERT_EQ(solution.fib(3), 2);
    ASSERT_EQ(solution.fib(4), 3);
    ASSERT_EQ(solution.fib(5), 5);
    ASSERT_EQ(solution.fib(6), 8);
    ASSERT_EQ(solution.fib(30), 832040);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
