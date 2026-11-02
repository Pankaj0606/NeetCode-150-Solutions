import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        Queue<Pair<TreeNode, TreeNode>> queue = new LinkedList<>();
        queue.offer(new Pair<>(p, q));
        while (!queue.isEmpty()) {
            Pair<TreeNode, TreeNode> cur = queue.poll();
            TreeNode a = cur.getKey();
            TreeNode b = cur.getValue();
            if (a == null && b == null) continue;
            if (a == null || b == null) return false;
            if (a.val != b.val) return false;
            queue.offer(new Pair<>(a.left, b.left));
            queue.offer(new Pair<>(a.right, b.right));
        }
        return true;
    }
    // Simple Pair implementation to avoid JavaFX/Apache dependencies
    private static class Pair<K, V> {
        private final K key;
        private final V value;
        Pair(K k, V v) { key = k; value = v; }
        K getKey() { return key; }
        V getValue() { return value; }
    }
}
