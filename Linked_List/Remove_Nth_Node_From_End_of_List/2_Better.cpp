#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Use a stack to store nodes
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }
        // Pop n nodes to reach the predecessor
        for (int i = 0; i < n; ++i) {
            if (!st.empty()) st.pop();
        }
        // If stack is empty, we need to delete the head
        if (st.empty()) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* prev = st.top();
        ListNode* toDelete = prev->next;
        prev->next = prev->next->next;
        delete toDelete;
        return head;
    }
};
