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
        unordered_map<Node*, Node*> mp;
        // First pass: create copy nodes and store mapping
        Node* cur = head;
        while (cur) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // Second pass: assign next and random using the map
        cur = head;
        while (cur) {
            mp[cur]->next = cur->next ? mp[cur->next] : nullptr;
            mp[cur]->random = cur->random ? mp[cur->random] : nullptr;
            cur = cur->next;
        }
        return mp[head];
    }
};
