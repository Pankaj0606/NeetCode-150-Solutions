#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        // Store all nodes in a vector
        std::vector<ListNode*> nodes;
        for (ListNode* cur = head; cur; cur = cur->next) {
            nodes.push_back(cur);
        }
        int n = nodes.size();
        // Process each full group
        for (int i = 0; i + k <= n; i += k) {
            // reverse pointers within the group
            for (int l = i, r = i + k - 1; l < r; ++l, --r) {
                std::swap(nodes[l], nodes[r]);
            }
        }
        // Re‑link the list according to the new order in the vector
        for (int i = 0; i < n - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes.back()->next = nullptr;
        return nodes[0];
    }
};
