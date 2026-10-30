class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        // Brute force: recompute height for every node
        int curHeight = height(root);
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return std::max({curHeight, leftDepth, rightDepth});
    }
private:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }
};
