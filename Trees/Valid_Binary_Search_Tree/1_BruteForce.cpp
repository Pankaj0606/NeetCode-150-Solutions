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
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
private:
    bool helper(TreeNode* node) {
        if (!node) return true;
        if (node->left && maxValue(node->left) >= node->val) return false;
        if (node->right && minValue(node->right) <= node->val) return false;
        return helper(node->left) && helper(node->right);
    }
    int maxValue(TreeNode* node) {
        while (node->right) node = node->right;
        return node->val;
    }
    int minValue(TreeNode* node) {
        while (node->left) node = node->left;
        return node->val;
    }
};
