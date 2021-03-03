# pragma once 

#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n);
private:
    int recursion_force(int n);
    int top_down_with_memoization(vector<int>& cache, int n);
    int bottom_up_with_memoization(int n);
    int bottom_up_iterative(int n);
};