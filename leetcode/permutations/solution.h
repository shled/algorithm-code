# pragma once

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums);
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& track);
    void backtrack_plus(vector<int>& nums, vector<vector<int>>& res, int first);
};