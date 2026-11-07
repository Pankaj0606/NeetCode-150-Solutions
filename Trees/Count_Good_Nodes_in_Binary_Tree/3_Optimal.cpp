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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int good = 0;
        int maxSoFar = INT_MIN;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                // visit cur
                if (cur->val >= maxSoFar) ++good;
                maxSoFar = max(maxSoFar, cur->val);
                cur = cur->right;
            } else {
                // find predecessor
                TreeNode* pred = cur->left;
                while (pred->right && pred->right != cur) pred = pred->right;
                if (!pred->right) {
                    // create thread
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    // thread exists, remove it and visit cur
                    pred->right = nullptr;
                    if (cur->val >= maxSoFar) ++good;
                    maxSoFar = max(maxSoFar, cur->val);
                    cur = cur->right;
                }
            }
        }
        return good;
    }
};
