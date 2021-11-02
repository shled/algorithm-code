# pragma once

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target);
private:
    int left_bound(vector<int>& nums, int target);
    int right_bound(vector<int>& nums, int target);
    int binary_search(vector<int>& nums, int target, bool lower);
};