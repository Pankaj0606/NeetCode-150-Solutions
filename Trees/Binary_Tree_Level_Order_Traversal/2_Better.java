class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<TreeNode> cur = new LinkedList<>();
        Queue<TreeNode> nxt = new LinkedList<>();
        cur.offer(root);
        while (!cur.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            while (!cur.isEmpty()) {
                TreeNode node = cur.poll();
                level.add(node.val);
                if (node.left != null) nxt.offer(node.left);
                if (node.right != null) nxt.offer(node.right);
            }
            res.add(level);
            Queue<TreeNode> temp = cur; cur = nxt; nxt = temp;
        }
        return res;
    }
}
