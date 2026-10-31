class Solution {
public:
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int rootDiameter = leftHeight + rightHeight;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max(rootDiameter, max(leftDiameter, rightDiameter));
    }
};
