#include "gtest/gtest.h"

#include "solution.h"

TEST(LEETCODE, n_queens) {
    Solution solution;
    vector<vector<string>> res = solution.solveNQueens(1);
    ASSERT_EQ(res.size(), 1);
    cout<<"n = 1"<<endl;
    for (auto board: res) {
        cout<<"<=============>"<<endl;
        for (auto row: board) {
            cout<<row<<endl;
        }
        cout<<"<=============>"<<endl;
    }

    res = solution.solveNQueens(4);
    ASSERT_EQ(res.size(), 2);
    cout<<"n = 4"<<endl;
    for (auto board: res) {
        cout<<"<=============>"<<endl;
        for (auto row: board) {
            cout<<row<<endl;
        }
        cout<<"<=============>"<<endl;
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}