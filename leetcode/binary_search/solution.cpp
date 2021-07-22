#include "solution.h"

int Solution::search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int pos = l + (r - l) / 2;
        if (nums[pos] == target) {
            return pos;
        } else if (nums[pos] > target) {
            r = pos - 1;
        } else {
            l = pos + 1;
        }
    }
    return -1;
}