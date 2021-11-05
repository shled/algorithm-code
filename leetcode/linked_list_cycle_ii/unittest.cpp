#include <vector>

#include "gtest/gtest.h"

#include "solution.h"

using namespace std;

ListNode* build_linked_list(const vector<int>& values, int pos) {
    if (values.size() <= 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    ListNode* cycle_node = nullptr;
    if (pos == 0) {
        cycle_node = head;
    }
    for (int i = 1; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        if (pos == i) {
            cycle_node = tail->next;
        }
        tail = tail->next;
    }

    tail->next = cycle_node;
    return head;
}

TEST(LEETCODE, linked_list_cycle_ii) {
    Solution solution;

    ASSERT_EQ(solution.detectCycle(build_linked_list(vector<int>{3, 2, 0, -4}, 1))->val, 2);
    ASSERT_EQ(solution.detectCycle(build_linked_list(vector<int>{1, 2}, 0))->val, 1);
    ASSERT_EQ(solution.detectCycle(build_linked_list(vector<int>{1}, -1)), nullptr);
    ASSERT_EQ(solution.detectCycle(build_linked_list(vector<int>{}, -1)), nullptr);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}