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
    // Returns height if balanced, otherwise -1
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int lh = dfs(node->left);
        if (lh == -1) return -1; // left subtree unbalanced
        int rh = dfs(node->right);
        if (rh == -1) return -1; // right subtree unbalanced
        if (abs(lh - rh) > 1) return -1; // current node unbalanced
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
