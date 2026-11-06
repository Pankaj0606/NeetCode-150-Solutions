import java.util.*;
class TreeNode {
    int val; TreeNode left; TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left = left; this.right = right; }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        dfs(root, 0, ans);
        return ans;
    }
    private void dfs(TreeNode node, int depth, List<Integer> ans) {
        if (node == null) return;
        if (depth == ans.size()) ans.add(node.val); // first node encountered at this depth
        dfs(node.right, depth + 1, ans); // right child first
        dfs(node.left, depth + 1, ans);
    }
}
