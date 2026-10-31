class Solution {
public:
    int diameter = 0;
    int depth(TreeNode* node) {
        if (!node) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};
