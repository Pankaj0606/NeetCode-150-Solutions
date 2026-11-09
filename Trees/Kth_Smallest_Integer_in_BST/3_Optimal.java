/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        int count = 0;
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left == null) {
                if (++count == k) return cur.val;
                cur = cur.right;
            } else {
                TreeNode pred = cur.left;
                while (pred.right != null && pred.right != cur) {
                    pred = pred.right;
                }
                if (pred.right == null) {
                    pred.right = cur;
                    cur = cur.left;
                } else {
                    pred.right = null;
                    if (++count == k) return cur.val;
                    cur = cur.right;
                }
            }
        }
        return -1; // k is guaranteed to be valid per problem constraints
    }
}
