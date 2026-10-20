#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        stack<ListNode*> st;
        for (ListNode* cur = head; cur; cur = cur->next) st.push(cur);
        int n = st.size();
        ListNode* cur = head;
        for (int i = 0; i < n / 2; ++i) {
            ListNode* top = st.top(); st.pop();
            ListNode* nxt = cur->next;
            cur->next = top;
            top->next = nxt;
            cur = nxt;
        }
        cur->next = nullptr; // terminate
    }
};
