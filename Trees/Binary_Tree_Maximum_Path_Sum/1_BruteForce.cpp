#include <bits/stdc++.h>
using namespace std;
/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfsAll(root, ans);
        return ans;
    }
private:
    // Visit every node and treat it as the highest point of the path
    void dfsAll(TreeNode* node, int& ans) {
        if (!node) return;
        int left = maxDown(node->left);
        int right = maxDown(node->right);
        int cur = node->val + max(0, left) + max(0, right);
        ans = max(ans, cur);
        dfsAll(node->left, ans);
        dfsAll(node->right, ans);
    }
    // Maximum sum from node down to any descendant (ignores negative branches)
    int maxDown(TreeNode* node) {
        if (!node) return 0;
        int left = maxDown(node->left);
        int right = maxDown(node->right);
        return node->val + max(0, max(left, right));
    }
};
