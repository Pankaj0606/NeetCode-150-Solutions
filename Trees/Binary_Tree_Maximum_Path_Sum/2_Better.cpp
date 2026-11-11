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
        maxGain(root, ans);
        return ans;
    }
private:
    // Returns the maximum gain from this node upward and updates global answer
    int maxGain(TreeNode* node, int& ans) {
        if (!node) return 0;
        int left = max(0, maxGain(node->left, ans));
        int right = max(0, maxGain(node->right, ans));
        ans = max(ans, node->val + left + right); // path that passes through node
        return node->val + max(left, right);      // gain to parent
    }
};
