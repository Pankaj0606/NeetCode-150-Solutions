/** Definition for a binary tree node. */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
import java.util.*;
class Solution {
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        int ans = Integer.MIN_VALUE;
        Map<TreeNode, Integer> gain = new HashMap<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.peek();
            if (node.left != null && !gain.containsKey(node.left)) { stack.push(node.left); continue; }
            if (node.right != null && !gain.containsKey(node.right)) { stack.push(node.right); continue; }
            stack.pop();
            int left = node.left != null ? Math.max(0, gain.get(node.left)) : 0;
            int right = node.right != null ? Math.max(0, gain.get(node.right)) : 0;
            ans = Math.max(ans, node.val + left + right);
            gain.put(node, node.val + Math.max(left, right));
        }
        return ans;
    }
}
