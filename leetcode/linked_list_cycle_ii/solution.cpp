#include "solution.h"

ListNode *Solution::detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    ListNode* ptr = head;
    while (ptr != fast) {
        ptr = ptr->next;
        fast = fast->next;
    }

    return ptr;
}