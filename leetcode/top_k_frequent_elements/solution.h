# pragma once

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
private:
    int partition(vector<pair<int, int>>& values, int begin, int end);
    vector<int> quick_select(unordered_map<int, int>& occurrences, int k);
    void min_heapify(vector<pair<int, int>>& values, int i, int heap_size);
    vector<int> heap(unordered_map<int, int>& occurrences, int k);
};