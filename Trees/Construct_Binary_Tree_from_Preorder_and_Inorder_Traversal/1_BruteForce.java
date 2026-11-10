import java.util.*;
/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // Brute‑force: copy sub‑arrays and linear search for root.
        if (preorder.length == 0) return null;
        int rootVal = preorder[0];
        TreeNode root = new TreeNode(rootVal);
        int idx = 0;
        while (idx < inorder.length && inorder[idx] != rootVal) idx++;
        // left parts
        int[] leftPre = Arrays.copyOfRange(preorder, 1, 1 + idx);
        int[] leftIn = Arrays.copyOfRange(inorder, 0, idx);
        // right parts
        int[] rightPre = Arrays.copyOfRange(preorder, 1 + idx, preorder.length);
        int[] rightIn = Arrays.copyOfRange(inorder, idx + 1, inorder.length);
        root.left = buildTree(leftPre, leftIn);
        root.right = buildTree(rightPre, rightIn);
        return root;
    }
}
