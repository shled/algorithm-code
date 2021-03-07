#include "solution.h"

#include<limits.h>

int Solution::coinChange(vector<int>& coins, int amount) {
    // return brute_force_backtracking(coins, amount);
    // return brute_force_dfs(coins, amount);
    // vector<int> cache(amount + 1, 0);
    // return dp_top_down(coins, amount, cache);
    return dp_bottom_up(coins, amount);
}

int Solution::brute_force_backtracking(vector<int>& coins, int amount) {
    return backtracking(0, coins, amount);
}

int Solution::backtracking(int index, vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (index < coins.size() && amount > 0) {
        int max_val = amount / coins[index];
        int min_cost = INT_MAX;
        for (int x = 0; x <= max_val; x++) {
            int res = backtracking(index + 1, coins, amount - x * coins[index]);
            if (res != -1) {
                min_cost = min(min_cost, res + x);
            }
        }
        return min_cost == INT_MAX ? -1 : min_cost;
    }
    return -1;
}

int Solution::brute_force_dfs(vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    int res = INT_MAX;
    for (int coin: coins) {
        int sub_res = brute_force_dfs(coins, amount - coin);
        if (sub_res == -1) {
            continue;
        }
        res = min(res, 1 + sub_res);
    }
    return res == INT_MAX ? -1 : res;
}

int Solution::dp_top_down(vector<int>& coins, int amount, vector<int>& cache) {
    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return -1;
    }
    if (cache[amount] != 0) {
        return cache[amount];
    }
    int res = INT_MAX;
    for (int coin: coins) {
        int sub_res = dp_top_down(coins, amount - coin, cache);
        if (sub_res == -1) {
            continue;
        }
        res = min(res, 1 + sub_res);
    }
    cache[amount] = res == INT_MAX ? -1 : res;
    return cache[amount];
}

int Solution::dp_bottom_up(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
        for (int coin: coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}