#include "solution.h"

#include <unordered_map>
#include <iostream>

vector<int> Solution::topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occurrences;
    for (auto& v: nums) {
        occurrences[v]++;
    }
    // return quick_select(occurrences, k);
    return heap(occurrences, k);
}

int Solution::partition(vector<pair<int, int>>& values, int begin, int end) {
    pair<int, int> pivot = values[begin];
    while (begin < end) {
        while (begin < end && values[end].second <= pivot.second) {
            end--;
        }
        values[begin] = values[end];

        while (begin < end && values[begin].second >= pivot.second) {
            begin++;
        }
        values[end] = values[begin];
    }
    values[begin] = pivot;
    return begin;
}

vector<int> Solution::quick_select(unordered_map<int, int>& occurrences, int k) {
    vector<pair<int, int>> values;
    for (auto& kv: occurrences) {
        values.emplace_back(kv);
    }
    int begin = 0, end = values.size() - 1;
    while (begin <= end) {
        int pos = partition(values, begin, end);
        if (pos == k - 1) {
            break;
        } else if (pos > k - 1) {
            end = pos - 1;
        } else {
            begin = pos + 1;
        }
    }
    vector<int> ret;
    for (int i = 0; i < k; i++) {
        ret.emplace_back(values[i].first);
    }
    return ret;
}

void Solution::min_heapify(vector<pair<int, int>>& values, int i, int heap_size) {
    int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
    if (l < heap_size && values[l].second < values[smallest].second) {
        smallest = l;
    }
    if (r < heap_size && values[r].second < values[smallest].second) {
        smallest = r;
    }
    if (smallest != i) {
        swap(values[smallest], values[i]);
        min_heapify(values, smallest, heap_size);
    }
}

vector<int> Solution::heap(unordered_map<int, int>& occurrences, int k) {
    vector<pair<int, int>> values;
    for (auto& kv: occurrences) {
        if (values.size() == k) {
            for (int i = values.size() / 2 - 1; i >= 0; i--) {
                min_heapify(values, i, values.size());
            }
        } 

        if (values.size() < k) {
            values.emplace_back(kv);
        } else {
            if (kv.second > values[0].second) {
                values[0] = kv;
                min_heapify(values, 0, values.size());
            }
        }
    }
    vector<int> ret;
    for (int i = 0; i < k; i++) {
        ret.emplace_back(values[i].first);
    }
    return ret;
}