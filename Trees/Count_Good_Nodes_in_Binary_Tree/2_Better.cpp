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
        return dfs(root, INT_MIN);
    }
private:
    int dfs(TreeNode* node, int maxSoFar) {
        if (!node) return 0;
        int good = (node->val >= maxSoFar) ? 1 : 0;
        int newMax = max(maxSoFar, node->val);
        good += dfs(node->left, newMax);
        good += dfs(node->right, newMax);
        return good;
    }
};
