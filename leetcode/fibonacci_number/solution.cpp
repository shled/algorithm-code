#include "solution.h"

int Solution::fib(int n) {
    // return recursion_force(n);
    // std::vector<int> cache(n + 1, 0);
    // return top_down_with_memoization(cache, n);
    // return bottom_up_with_memoization(n);
    return bottom_up_iterative(n);
}

int Solution::recursion_force(int n) {
    if (n < 2) {
        return n;
    }
    return recursion_force(n - 1) + recursion_force(n - 2);
}

int Solution::top_down_with_memoization(vector<int>& cache, int n) {
    if (n < 2) {
        return n;
    }
    if (cache[n] != 0) {
        return cache[n];
    }
    cache[n] = top_down_with_memoization(cache, n - 1) + top_down_with_memoization(cache, n - 2);
    return cache[n];
}

int Solution::bottom_up_with_memoization(int n) {
    if (n < 2) {
        return n;
    }
    std::vector<int> cache(n + 1, 0);
    cache[1] = 1;
    for (int i = 2; i <= n; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache[n];
}

int Solution::bottom_up_iterative(int n) {
    if (n < 2) {
        return n;
    }
    int cur = 0, n_1 = 1, n_2 = 0;
    for (int i = 2; i <= n; i++) {
        cur = n_1 + n_2;
        n_2 = n_1;
        n_1 = cur;
    }
    return cur;
}