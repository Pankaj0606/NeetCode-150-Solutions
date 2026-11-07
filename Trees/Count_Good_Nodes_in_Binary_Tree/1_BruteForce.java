import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    // Brute‑force: recompute max on the path for every node
    private int maxOnPath(TreeNode root, TreeNode target, int curMax) {
        if (root == null) return Integer.MIN_VALUE;
        curMax = Math.max(curMax, root.val);
        if (root == target) return curMax;
        int left = maxOnPath(root.left, target, curMax);
        if (left != Integer.MIN_VALUE) return left;
        return maxOnPath(root.right, target, curMax);
    }

    public int goodNodes(TreeNode root) {
        if (root == null) return 0;
        List<TreeNode> nodes = new ArrayList<>();
        // collect all nodes
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            nodes.add(node);
            if (node.right != null) stack.push(node.right);
            if (node.left != null) stack.push(node.left);
        }
        int good = 0;
        for (TreeNode n : nodes) {
            int pathMax = maxOnPath(root, n, Integer.MIN_VALUE);
            if (n.val >= pathMax) good++;
        }
        return good;
    }
}
