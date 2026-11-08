public class Solution {
    public boolean isValidBST(TreeNode root) {
        java.util.List<Long> inorder = new java.util.ArrayList<>();
        inorderTraversal(root, inorder);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder.get(i) <= inorder.get(i - 1)) return false;
        }
        return true;
    }
    private void inorderTraversal(TreeNode node, java.util.List<Long> list) {
        if (node == null) return;
        inorderTraversal(node.left, list);
        list.add((long) node.val);
        inorderTraversal(node.right, list);
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
