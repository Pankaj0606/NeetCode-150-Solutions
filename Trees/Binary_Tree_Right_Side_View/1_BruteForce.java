import java.util.*;
/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<List<Integer>> levels = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while (!q.isEmpty()) {
            int sz = q.size();
            List<Integer> cur = new ArrayList<>();
            for (int i = 0; i < sz; i++) {
                TreeNode node = q.poll();
                cur.add(node.val);
                if (node.left != null) q.offer(node.left);
                if (node.right != null) q.offer(node.right);
            }
            levels.add(cur);
        }
        List<Integer> ans = new ArrayList<>();
        for (List<Integer> lvl : levels) ans.add(lvl.get(lvl.size() - 1));
        return ans;
    }
}
