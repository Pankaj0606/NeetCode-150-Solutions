import java.util.*;
class Solution {
    private Map<TreeNode, Integer> memo = new HashMap<>();
    private int height(TreeNode node) {
        if (node == null) return 0;
        if (memo.containsKey(node)) return memo.get(node);
        int h = 1 + Math.max(height(node.left), height(node.right));
        memo.put(node, h);
        return h;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        int rootDiameter = leftHeight + rightHeight;
        int leftDiameter = diameterOfBinaryTree(root.left);
        int rightDiameter = diameterOfBinaryTree(root.right);
        return Math.max(rootDiameter, Math.max(leftDiameter, rightDiameter));
    }
}
