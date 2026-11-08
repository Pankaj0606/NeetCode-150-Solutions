public class Solution {
    public boolean isValidBST(TreeNode root) {
        return helper(root);
    }
    private boolean helper(TreeNode node) {
        if (node == null) return true;
        if (node.left != null && maxValue(node.left) >= node.val) return false;
        if (node.right != null && minValue(node.right) <= node.val) return false;
        return helper(node.left) && helper(node.right);
    }
    private int maxValue(TreeNode node) {
        while (node.right != null) node = node.right;
        return node.val;
    }
    private int minValue(TreeNode node) {
        while (node.left != null) node = node.left;
        return node.val;
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
