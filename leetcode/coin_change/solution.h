# pragma once

#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount);
private:
    int brute_force_backtracking(vector<int>& coins, int amount);
    int backtracking(int index, vector<int>& coins, int amount);
    int brute_force_dfs(vector<int>& coins, int amount);
    int dp_top_down(vector<int>& coins, int amount, vector<int>& cache);
    int dp_bottom_up(vector<int>& coins, int amount);
};