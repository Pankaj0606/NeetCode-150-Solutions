public class Solution {
    public boolean isValidBST(TreeNode root) {
        long[] prev = new long[]{Long.MIN_VALUE};
        return inorder(root, prev);
    }
    private boolean inorder(TreeNode node, long[] prev) {
        if (node == null) return true;
        if (!inorder(node.left, prev)) return false;
        if (node.val <= prev[0]) return false;
        prev[0] = node.val;
        return inorder(node.right, prev);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
