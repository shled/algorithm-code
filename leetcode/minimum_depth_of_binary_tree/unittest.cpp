#include <vector>
#include <queue>

#include "gtest/gtest.h"

#include "solution.h"

using namespace std;

TreeNode* build_tree(vector<int>& values) {
    if (values.size() <= 0) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.emplace(root);
    for (int i = 1; i < values.size();) {
        TreeNode* parent = q.front();
        q.pop();

        int left_val = values[i];
        TreeNode* left = left_val <= 1000 ? new TreeNode(left_val) : nullptr;
        parent->left = left;
        if (left != nullptr) {
            q.emplace(left);
        }

        i++;

        if (i >= values.size()) {
            break;
        }
        int right_val = values[i];
        TreeNode* right = right_val <= 1000 ? new TreeNode(right_val) : nullptr;
        parent->right = right;
        if (right != nullptr) {
            q.emplace(right);
        }

        i++;
    }

    return root;
}

TEST(LEETCODE, minimum_depth_of_binary_tree) {
    Solution solution;

    vector<int> values = {3, 9, 20, 1024, 1024, 15, 7};
    // ASSERT_EQ(solution.minDepth(build_tree(values)), 2);
    values = {2, 1024, 3, 1024, 4, 1024, 5, 1024, 6};
    ASSERT_EQ(solution.minDepth(build_tree(values)), 5);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}