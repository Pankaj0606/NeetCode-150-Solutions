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
        long long prev = LLONG_MIN;
        return inorder(root, prev);
    }
private:
    bool inorder(TreeNode* node, long long& prev) {
        if (!node) return true;
        if (!inorder(node->left, prev)) return false;
        if (node->val <= prev) return false;
        prev = node->val;
        return inorder(node->right, prev);
    }
};
