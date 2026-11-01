#include <bits/stdc++.h>
using namespace std;
/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if (abs(lh - rh) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
