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
        // First pass: compute length
        int length = 0;
        ListNode* cur = head;
        while (cur) {
            ++length;
            cur = cur->next;
        }
        int target = length - n; // zero‑based index from start
        // Dummy node simplifies removal of head
        ListNode dummy(0);
        dummy.next = head;
        cur = &dummy;
        for (int i = 0; i < target; ++i) {
            cur = cur->next;
        }
        ListNode* toDelete = cur->next;
        cur->next = cur->next->next;
        delete toDelete;
        return dummy.next;
    }
};
