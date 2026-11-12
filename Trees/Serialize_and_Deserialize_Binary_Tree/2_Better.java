import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Codec {
    // Use StringBuilder for O(N) serialization
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        buildString(root, sb);
        return sb.toString();
    }

    private void buildString(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("null,");
            return;
        }
        sb.append(node.val).append(',');
        buildString(node.left, sb);
        buildString(node.right, sb);
    }

    // Deserialize – split once then reconstruct recursively
    public TreeNode deserialize(String data) {
        String[] tokens = data.split(",");
        int[] idx = new int[]{0};
        return buildTree(tokens, idx);
    }

    private TreeNode buildTree(String[] tokens, int[] idx) {
        if (idx[0] >= tokens.length || tokens[idx[0]].equals("null")) {
            idx[0]++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(tokens[idx[0]++]));
        node.left = buildTree(tokens, idx);
        node.right = buildTree(tokens, idx);
        return node;
    }
}

// Example usage:
// Codec codec = new Codec();
// String s = codec.serialize(root);
// TreeNode restored = codec.deserialize(s);
