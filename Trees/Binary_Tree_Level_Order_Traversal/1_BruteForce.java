class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            List<Integer> level = new ArrayList<>();
            collectLevel(root, i, level);
            res.add(level);
        }
        return res;
    }
    private int height(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }
    private void collectLevel(TreeNode node, int level, List<Integer> out) {
        if (node == null) return;
        if (level == 1) out.add(node.val);
        else {
            collectLevel(node.left, level - 1, out);
            collectLevel(node.right, level - 1, out);
        }
    }
}
