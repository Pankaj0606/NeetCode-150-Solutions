/**
 * Definition for a binary tree node.
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    // Helper to collect path from root to target
    private boolean getPath(TreeNode root, TreeNode target, java.util.List<TreeNode> path) {
        if (root == null) return false;
        path.add(root);
        if (root == target) return true;
        if (getPath(root.left, target, path) || getPath(root.right, target, path))
            return true;
        path.remove(path.size() - 1);
        return false;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        java.util.List<TreeNode> pathP = new java.util.ArrayList<>();
        java.util.List<TreeNode> pathQ = new java.util.ArrayList<>();
        getPath(root, p, pathP);
        getPath(root, q, pathQ);
        TreeNode lca = null;
        int i = 0, n = Math.min(pathP.size(), pathQ.size());
        while (i < n && pathP.get(i) == pathQ.get(i)) {
            lca = pathP.get(i);
            i++;
        }
        return lca;
    }
}
