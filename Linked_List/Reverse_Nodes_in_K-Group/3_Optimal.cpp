#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        // Dummy node simplifies edge handling
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        while (true) {
            // Verify that a full group exists
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; ++i) kth = kth->next;
            if (!kth) break; // less than k nodes remain
            // Reverse the group
            ListNode* groupPrev = prevGroup->next; // will become tail after reversal
            ListNode* cur = prevGroup->next;
            ListNode* next = nullptr;
            ListNode* prev = kth->next; // node after the group
            for (int i = 0; i < k; ++i) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            // Connect previous part with the newly reversed head
            prevGroup->next = kth;
            // Move prevGroup pointer to the tail of the reversed group
            prevGroup = groupPrev;
        }
        return dummy.next;
    }
};
