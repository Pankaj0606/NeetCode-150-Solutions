/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* cloneAndInvert(TreeNode* node) {
        if (!node) return nullptr;
        TreeNode* newNode = new TreeNode(node->val);
        newNode->left = cloneAndInvert(node->right);
        newNode->right = cloneAndInvert(node->left);
        return newNode;
    }
    TreeNode* invertTree(TreeNode* root) {
        return cloneAndInvert(root);
    }
};
