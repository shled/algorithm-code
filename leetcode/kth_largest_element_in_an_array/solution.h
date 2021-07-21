# pragma once

#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k);
private:
    int quick_select(vector<int>& nums, int k);
    int partition_uni_direction(vector<int>& nums, int begin, int end);
    int partition_bi_direction(vector<int>& nums, int begin, int end);
    int heap_sort_select(vector<int>& nums, int k);
    void max_heapify(vector<int>& nums, int i, int heap_size);
};