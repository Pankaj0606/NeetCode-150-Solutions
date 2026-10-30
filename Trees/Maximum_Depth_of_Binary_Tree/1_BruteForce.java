class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        // Brute force: recompute height for every node
        int curHeight = height(root);
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);
        return Math.max(curHeight, Math.max(leftDepth, rightDepth));
    }
    private int height(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }
}
