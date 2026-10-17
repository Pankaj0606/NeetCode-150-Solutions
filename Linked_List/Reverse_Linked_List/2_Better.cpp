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
        return reverseRec(head, nullptr);
    }
private:
    ListNode* reverseRec(ListNode* curr, ListNode* prev) {
        if (!curr) return prev;
        ListNode* nxt = curr->next;
        curr->next = prev;
        return reverseRec(nxt, curr);
    }
};
