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
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                tail->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            tail = tail->next;
        }
        while (l1) {
            tail->next = new ListNode(l1->val);
            l1 = l1->next;
            tail = tail->next;
        }
        while (l2) {
            tail->next = new ListNode(l2->val);
            l2 = l2->next;
            tail = tail->next;
        }
        return dummy.next;
    }
};
