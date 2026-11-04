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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) {
                root = root.left; // Both nodes are in left subtree
            } else if (p.val > root.val && q.val > root.val) {
                root = root.right; // Both nodes are in right subtree
            } else {
                // We have found the split point
                return root;
            }
        }
        return null; // Should never be reached if p and q are guaranteed to exist
    }
}
