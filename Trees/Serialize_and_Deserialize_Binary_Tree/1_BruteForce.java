import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Codec {
    // Naïve string concatenation – O(N^2) for serialization
    public String serialize(TreeNode root) {
        if (root == null) return "null,";
        return root.val + "," + serialize(root.left) + serialize(root.right);
    }

    // Deserialize by splitting into a list of tokens
    public TreeNode deserialize(String data) {
        List<String> nodes = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (char c : data.toCharArray()) {
            if (c == ',') {
                nodes.add(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }
        int[] idx = new int[]{0};
        return build(nodes, idx);
    }

    private TreeNode build(List<String> nodes, int[] idx) {
        if (idx[0] >= nodes.size() || nodes.get(idx[0]).equals("null")) {
            idx[0]++;
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(nodes.get(idx[0]++)));
        node.left = build(nodes, idx);
        node.right = build(nodes, idx);
        return node;
    }
}

// LeetCode usage example:
// Codec codec = new Codec();
// String s = codec.serialize(root);
// TreeNode ans = codec.deserialize(s);
