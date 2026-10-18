#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<int> vals;
        while (l1) { vals.push_back(l1->val); l1 = l1->next; }
        while (l2) { vals.push_back(l2->val); l2 = l2->next; }
        sort(vals.begin(), vals.end());
        ListNode dummy(0);
        ListNode* cur = &dummy;
        for (int v : vals) {
            cur->next = new ListNode(v);
            cur = cur->next;
        }
        return dummy.next;
    }
};
