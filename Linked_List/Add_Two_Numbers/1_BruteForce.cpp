#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // Brute‑force: convert to strings, add as big integers, rebuild list
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        while (l1) { s1.push_back('0' + l1->val); l1 = l1->next; }
        while (l2) { s2.push_back('0' + l2->val); l2 = l2->next; }
        // digits are reversed; reverse strings to get true order
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        // big‑integer addition on strings
        string res;
        int i = (int)s1.size() - 1, j = (int)s2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            res.push_back('0' + (sum % 10));
            carry = sum / 10;
        }
        // res currently holds digits in reverse order (least‑significant first)
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        for (char c : res) {
            ListNode* node = new ListNode(c - '0');
            if (!head) head = cur = node;
            else { cur->next = node; cur = node; }
        }
        return head;
    }
};
