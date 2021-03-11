#include "solution.h"

#include <algorithm>

vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> res;
    // vector<int> track;
    // backtrack(nums, res, track);
    backtrack_plus(nums, res, 0);
    return res;
}

void Solution::backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& track) {
    if (track.size() == nums.size()) {
        res.push_back(track);
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (find(track.begin(), track.end(), nums[i]) != track.end()) {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, res, track);
            track.pop_back();
        }
    }
}

void Solution::backtrack_plus(vector<int>& nums, vector<vector<int>>& res, int first) {
    if (first >= nums.size()) {
        res.push_back(nums);
    } else {
        for (int i = first; i < nums.size(); i++) {
            swap(nums[first], nums[i]);
            backtrack_plus(nums, res, first + 1);
            swap(nums[first], nums[i]);
        }
    }
}