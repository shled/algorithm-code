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

TEST(LEETCODE, remove_nth_node_from_end_of_list) {
    Solution solution;
    ListNode* head = nullptr;

    head = solution.removeNthFromEnd(build_linked_list(vector<int>{1, 2, 3, 4, 5}), 2);
    ASSERT_EQ(head->val, 1);
    ASSERT_EQ(head->next->val, 2);
    ASSERT_EQ(head->next->next->val, 3);
    ASSERT_EQ(head->next->next->next->val, 5);
    ASSERT_EQ(head->next->next->next->next, nullptr);

    head = solution.removeNthFromEnd(build_linked_list(vector<int>{1}), 1);
    ASSERT_EQ(head, nullptr);

    head = solution.removeNthFromEnd(build_linked_list(vector<int>{1, 2}), 1);
    ASSERT_EQ(head->val, 1);
    ASSERT_EQ(head->next, nullptr);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}