#include "gtest/gtest.h"

#include <iostream>

#include "solution.h"

TEST(LEETCODE, reverse_string) {
    Solution solution;

    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s1);
    for (auto& c: s1) {cout<<c;} cout<<endl;

    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s2);
    for (auto& c: s2) {cout<<c;} cout<<endl;
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}