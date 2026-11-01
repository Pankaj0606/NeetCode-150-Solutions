/** Definition for a binary tree node. */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Returns height if balanced, otherwise -1
    private int dfs(TreeNode node) {
        if (node == null) return 0;
        int lh = dfs(node.left);
        if (lh == -1) return -1;
        int rh = dfs(node.right);
        if (rh == -1) return -1;
        if (Math.abs(lh - rh) > 1) return -1;
        return 1 + Math.max(lh, rh);
    }
    public boolean isBalanced(TreeNode root) {
        return dfs(root) != -1;
    }
}
