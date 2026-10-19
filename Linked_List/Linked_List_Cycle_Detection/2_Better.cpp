#include <cstddef>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        // Reverse while traversing
        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev; // reverse link
            prev = curr;
            curr = nextNode;
            // If we ever hit nullptr, list terminates → no cycle
            if (!curr) {
                // Restore original order before returning
                restore(prev);
                return false;
            }
            // If we meet the original head again, a cycle exists
            if (curr == head) {
                // Restore before returning true
                restore(prev);
                return true;
            }
        }
        return false; // unreachable
    }
private:
    // Helper to restore the reversed part back to original order
    void restore(ListNode *node) {
        ListNode *prev = nullptr;
        while (node) {
            ListNode *nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
        }
    }
};
