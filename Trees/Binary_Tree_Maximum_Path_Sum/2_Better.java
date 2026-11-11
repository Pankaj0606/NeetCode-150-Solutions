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
        maxGain(root, ans);
        return ans[0];
    }
    private int maxGain(TreeNode node, int[] ans) {
        if (node == null) return 0;
        int left = Math.max(0, maxGain(node.left, ans));
        int right = Math.max(0, maxGain(node.right, ans));
        ans[0] = Math.max(ans[0], node.val + left + right);
        return node.val + Math.max(left, right);
    }
}
