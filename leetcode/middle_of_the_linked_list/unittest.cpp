#include <vector>

#include "gtest/gtest.h"

#include "solution.h"

using namespace std;

ListNode* build_linked_list(const vector<int>& values) {
    if (values.size() <= 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    for (int i = 1; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    return head;
}

TEST(LEETCODE, linked_list_cycle) {
    Solution solution;

    ASSERT_EQ(solution.middleNode(build_linked_list(vector<int>{1, 2, 3, 4, 5}))->val, 3);
    ASSERT_EQ(solution.middleNode(build_linked_list(vector<int>{1, 2, 3, 4, 5, 6}))->val, 4);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}