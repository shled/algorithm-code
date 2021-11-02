#include "solution.h"

vector<int> Solution::searchRange(vector<int>& nums, int target) {
    // int left = left_bound(nums, target);
    // int right = right_bound(nums, target);
    // return vector<int>{left, right};

    int left = binary_search(nums, target, true);
    int right = binary_search(nums, target, false) - 1;
    if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target) {
        return vector<int>{left, right};
    } 
    return vector<int>{-1, -1};
}

int Solution::left_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    if (left >= nums.size() || nums[left] != target) {
        return -1;
    }
    return left;
}

int Solution::right_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}

int Solution::binary_search(vector<int>& nums, int target, bool lower) {
    int left = 0, right = nums.size() - 1, ans = nums.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
            ans = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            if (lower) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
    }
    return ans;
}