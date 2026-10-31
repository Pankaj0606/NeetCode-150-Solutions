class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int height(TreeNode* node) {
        if (!node) return 0;
        if (memo.count(node)) return memo[node];
        memo[node] = 1 + max(height(node->left), height(node->right));
        return memo[node];
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
