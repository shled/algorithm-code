#include "solution.h"

#include <iostream>

int Solution::findKthLargest(vector<int>& nums, int k) {
    // return quick_select(nums, k);
    return heap_sort_select(nums, k);
}

int Solution::quick_select(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        // int pos = partition_uni_direction(nums, l, r);
        int pos = partition_bi_direction(nums, l, r);
        int sort_k = nums.size() - pos;
        if (sort_k == k) {
            return nums[pos];
        } else if (sort_k > k) {
            l = pos + 1;
        } else {
            r = pos - 1;
        }
    }
    return -1;
}

int Solution::partition_uni_direction(vector<int>& nums, int begin, int end) {
    int pivot = nums[begin];
    int pos = begin;
    for (int i = begin + 1; i <= end; i++) {
        if (nums[i] < pivot) {
            pos++;
            if (pos != i) {
                swap(nums[pos], nums[i]);
            }
        }
    }
    swap(nums[pos], nums[begin]);
    return pos;
}

int Solution::partition_bi_direction(vector<int>& nums, int begin, int end) {
    int pivot = nums[begin];
    while (begin < end) {
        while (begin < end && nums[end] >= pivot) {
            end--;
        }
        nums[begin] = nums[end];

        while (begin < end && nums[begin] <= pivot) {
            begin++;
        }
        nums[end] = nums[begin];
    }
    nums[begin] = pivot;
    return begin;
}

int Solution::heap_sort_select(vector<int>& nums, int k) {
    int heap_size = nums.size();
    for (int i = (heap_size / 2) - 1; i >= 0; i--) {
        max_heapify(nums, i, heap_size);
    }
    for (int i = nums.size() - 1; i > nums.size() - k; i--) {
        swap(nums[0], nums[i]);
        heap_size--;
        max_heapify(nums, 0, heap_size);
    }
    return nums[0];
}

void Solution::max_heapify(vector<int>& nums, int i, int heap_size) {
    int l = i * 2 + 1, r = i * 2 + 2, largest = i;
    if (l < heap_size && nums[l] > nums[largest]) {
        largest = l;
    }
    if (r < heap_size && nums[r] > nums[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(nums[i], nums[largest]);
        max_heapify(nums, largest, heap_size);
    }
}