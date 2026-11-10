import java.util.*;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
class Solution {
    private Map<Integer,Integer> idxMap;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        idxMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) idxMap.put(inorder[i], i);
        return build(preorder, 0, preorder.length, inorder, 0, inorder.length);
    }
    private TreeNode build(int[] pre, int preL, int preR, int[] in, int inL, int inR) {
        if (preL >= preR || inL >= inR) return null;
        int rootVal = pre[preL];
        TreeNode root = new TreeNode(rootVal);
        int idx = idxMap.get(rootVal);
        int leftSize = idx - inL;
        root.left = build(pre, preL + 1, preL + 1 + leftSize, in, inL, idx);
        root.right = build(pre, preL + 1 + leftSize, preR, in, idx + 1, inR);
        return root;
    }
}
