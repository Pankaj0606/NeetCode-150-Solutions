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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        // Move both until fast reaches the end
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        // Delete the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return dummy.next;
    }
};
