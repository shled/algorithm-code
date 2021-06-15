# pragma once

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target);
private:
    int bfs(vector<string>& deadends, string target);
};