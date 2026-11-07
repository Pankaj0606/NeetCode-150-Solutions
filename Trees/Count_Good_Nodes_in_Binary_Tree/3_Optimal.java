import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public int goodNodes(TreeNode root) {
        if (root == null) return 0;
        int good = 0;
        int maxSoFar = Integer.MIN_VALUE;
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left == null) {
                if (cur.val >= maxSoFar) good++;
                maxSoFar = Math.max(maxSoFar, cur.val);
                cur = cur.right;
            } else {
                // find predecessor
                TreeNode pred = cur.left;
                while (pred.right != null && pred.right != cur) {
                    pred = pred.right;
                }
                if (pred.right == null) {
                    pred.right = cur; // create thread
                    cur = cur.left;
                } else {
                    pred.right = null; // remove thread
                    if (cur.val >= maxSoFar) good++;
                    maxSoFar = Math.max(maxSoFar, cur.val);
                    cur = cur.right;
                }
            }
        }
        return good;
    }
}
