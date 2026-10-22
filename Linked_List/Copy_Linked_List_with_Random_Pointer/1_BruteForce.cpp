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
        // First pass: copy nodes preserving next pointers only
        Node* cur = head;
        Node dummy(0);
        Node* copyCur = &dummy;
        while (cur) {
            copyCur->next = new Node(cur->val);
            copyCur = copyCur->next;
            cur = cur->next;
        }
        Node* copyHead = dummy.next;
        // Second pass: set random pointers by linear search (O(N^2))
        Node* orig = head;
        Node* copy = copyHead;
        while (orig) {
            if (orig->random) {
                // Find the target node in original list
                Node* target = orig->random;
                Node* tOrig = head;
                Node* tCopy = copyHead;
                while (tOrig && tOrig != target) {
                    tOrig = tOrig->next;
                    tCopy = tCopy->next;
                }
                copy->random = tCopy; // tCopy will be nullptr only if not found (shouldn't happen)
            } else {
                copy->random = nullptr;
            }
            orig = orig->next;
            copy = copy->next;
        }
        return copyHead;
    }
};
