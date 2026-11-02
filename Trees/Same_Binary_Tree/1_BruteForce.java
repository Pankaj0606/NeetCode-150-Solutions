import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        String s1 = serialize(p);
        String s2 = serialize(q);
        return s1.equals(s2);
    }
    private String serialize(TreeNode node) {
        if (node == null) return "#,"; // sentinel for null
        return node.val + "," + serialize(node.left) + serialize(node.right);
    }
}
