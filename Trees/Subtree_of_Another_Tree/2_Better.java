import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

class Solution {
    private String serialize(TreeNode node) {
        if (node == null) return "#,"; // sentinel for null
        StringBuilder sb = new StringBuilder();
        sb.append(node.val).append(',');
        sb.append(serialize(node.left));
        sb.append(serialize(node.right));
        return sb.toString();
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        String rootSer = serialize(root);
        String subSer = serialize(subRoot);
        return rootSer.contains(subSer);
    }
}
