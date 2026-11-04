#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left; // Both in left subtree
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right; // Both in right subtree
            } else {
                // We have diverged or hit one of the nodes
                return root;
            }
        }
        return nullptr; // Should never happen if p and q are guaranteed to exist
    }
};
