import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root, Integer.MIN_VALUE);
    }

    private int dfs(TreeNode node, int maxSoFar) {
        if (node == null) return 0;
        int good = (node.val >= maxSoFar) ? 1 : 0;
        int newMax = Math.max(maxSoFar, node.val);
        good += dfs(node.left, newMax);
        good += dfs(node.right, newMax);
        return good;
    }
}
