#include <vector>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        std::vector<ListNode*> nodes;
        for (ListNode* cur = head; cur; cur = cur->next) {
            nodes.push_back(cur);
        }
        // Re‑link in reverse order
        for (int i = static_cast<int>(nodes.size()) - 1; i > 0; --i) {
            nodes[i]->next = nodes[i - 1];
        }
        nodes[0]->next = nullptr;
        return nodes.back();
    }
};
