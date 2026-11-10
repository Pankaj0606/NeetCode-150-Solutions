import java.util.*;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return helper(preorder, 0, preorder.length, inorder, 0, inorder.length);
    }
    private TreeNode helper(int[] pre, int preL, int preR, int[] in, int inL, int inR) {
        if (preL >= preR || inL >= inR) return null;
        int rootVal = pre[preL];
        TreeNode root = new TreeNode(rootVal);
        int idx = inL;
        while (idx < inR && in[idx] != rootVal) idx++;
        int leftSize = idx - inL;
        root.left = helper(pre, preL + 1, preL + 1 + leftSize, in, inL, idx);
        root.right = helper(pre, preL + 1 + leftSize, preR, in, idx + 1, inR);
        return root;
    }
}
