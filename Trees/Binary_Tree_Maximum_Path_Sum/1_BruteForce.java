/** Definition for a binary tree node. */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    public int maxPathSum(TreeNode root) {
        int[] ans = new int[]{Integer.MIN_VALUE};
        dfsAll(root, ans);
        return ans[0];
    }
    private void dfsAll(TreeNode node, int[] ans) {
        if (node == null) return;
        int left = maxDown(node.left);
        int right = maxDown(node.right);
        int cur = node.val + Math.max(0, left) + Math.max(0, right);
        ans[0] = Math.max(ans[0], cur);
        dfsAll(node.left, ans);
        dfsAll(node.right, ans);
    }
    private int maxDown(TreeNode node) {
        if (node == null) return 0;
        int left = maxDown(node.left);
        int right = maxDown(node.right);
        return node.val + Math.max(0, Math.max(left, right));
    }
}
