#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // 1. Weave copy nodes with original list
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        // 2. Assign random pointers for copy nodes
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            } else {
                cur->next->random = nullptr;
            }
            cur = cur->next->next;
        }
        // 3. Unweave to separate the two lists
        Node* dummy = new Node(0);
        Node* copyCur = dummy;
        cur = head;
        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next; // restore original next
            copyCur->next = copy;   // build copied list
            copyCur = copyCur->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
