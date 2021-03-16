# pragma once

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n);
private:
    void backtrack(int row, vector<string>& board);
    bool is_valid(int row, int col, vector<string>& board);
    vector<vector<string>> res;
};