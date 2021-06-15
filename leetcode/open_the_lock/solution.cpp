#include "solution.h"

#include <queue>
#include <unordered_set>

using namespace std;

int Solution::openLock(vector<string>& deadends, string target) {
    return bfs(deadends, target);
}

int Solution::bfs(vector<string>& deadends, string target) {
    unordered_set<string> deads;
    for (string s: deadends) {
        deads.insert(s);
    }
    queue<string> q;
    q.emplace("0000");
    unordered_set<string> visited;
    visited.insert("0000");

    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            if (deads.find(cur) != deads.end()) {
                continue;
            }
            if (cur == target) {
                return step;
            }
            for (int j = 0; j < 4; j++) {
                string s1 = cur, s2 = cur;
                s1[j] = s1[j] == '9' ? '0' : s1[j] + 1;
                s2[j] = s2[j] == '0' ? '9' : s2[j] - 1;
                if (visited.find(s1) == visited.end()) {
                    q.emplace(s1);
                    visited.insert(s1);
                }
                if (visited.find(s2) == visited.end()) {
                    q.emplace(s2);
                    visited.insert(s2);
                }
            }
        }
        step++;
    }
    return -1;
}
