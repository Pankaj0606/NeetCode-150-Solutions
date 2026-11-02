#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qnodes;
        qnodes.emplace(p, q);
        while (!qnodes.empty()) {
            auto [a, b] = qnodes.front();
            qnodes.pop();
            if (!a && !b) continue;          // both null – ok
            if (!a || !b) return false;      // structural mismatch
            if (a->val != b->val) return false;
            qnodes.emplace(a->left, b->left);
            qnodes.emplace(a->right, b->right);
        }
        return true;
    }
};
