#include "solution.h"

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (n-- > 0) {
        fast = fast->next;
    }
    if (fast == nullptr) {
        return slow->next;
    }
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}