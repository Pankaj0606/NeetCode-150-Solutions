/** Definition for a binary tree node. */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Helper returns an int array: [isBalanced (1/0), height]
    private int[] check(TreeNode node) {
        if (node == null) return new int[]{1, 0};
        int[] left = check(node.left);
        int[] right = check(node.right);
        boolean bal = left[0] == 1 && right[0] == 1 && Math.abs(left[1] - right[1]) <= 1;
        int h = 1 + Math.max(left[1], right[1]);
        return new int[]{bal ? 1 : 0, h};
    }
    public boolean isBalanced(TreeNode root) {
        return check(root)[0] == 1;
    }
}
