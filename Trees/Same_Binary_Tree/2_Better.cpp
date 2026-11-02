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
        return dfs(p, q);
    }
private:
    bool dfs(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;               // both null
        if (!a || !b) return false;              // one null
        if (a->val != b->val) return false;      // value mismatch
        return dfs(a->left, b->left) && dfs(a->right, b->right);
    }
};
