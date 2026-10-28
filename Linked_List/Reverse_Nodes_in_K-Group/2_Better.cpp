#include <stack>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    // Helper to reverse exactly k nodes and return new head
    ListNode* reverseK(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (k-- && cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev; // new head of reversed segment
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        // Check if there are at least k nodes left
        ListNode* ptr = head;
        for (int i = 0; i < k; ++i) {
            if (!ptr) return head; // not enough nodes, return as‑is
            ptr = ptr->next;
        }
        // Reverse first k nodes
        ListNode* newHead = reverseK(head, k);
        // head is now the tail of the reversed segment
        head->next = reverseKGroup(ptr, k);
        return newHead;
    }
};
