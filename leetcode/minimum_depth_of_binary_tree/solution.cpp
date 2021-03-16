#include "solution.h"

#include <queue>

using namespace std;

int Solution::minDepth(TreeNode* root) {
    return bfs(root);
}

int Solution::bfs(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<pair<TreeNode*, int>> q;
    q.emplace(root, 1);
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        if (node->left != nullptr) {
            q.emplace(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            q.emplace(node->right, depth + 1);
        }
    }
    return 0;
}