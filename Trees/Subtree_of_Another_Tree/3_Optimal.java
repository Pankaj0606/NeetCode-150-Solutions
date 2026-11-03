import java.util.*;

/** Definition for a binary tree node. */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

class Solution {
    private String serialize(TreeNode node) {
        if (node == null) return "#,";
        StringBuilder sb = new StringBuilder();
        sb.append(node.val).append(',');
        sb.append(serialize(node.left));
        sb.append(serialize(node.right));
        return sb.toString();
    }

    // Build LPS array for KMP
    private int[] buildLPS(String pat) {
        int m = pat.length();
        int[] lps = new int[m];
        for (int i = 1, len = 0; i < m; ) {
            if (pat.charAt(i) == pat.charAt(len)) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    private boolean kmpSearch(String txt, String pat) {
        if (pat.isEmpty()) return true;
        int[] lps = buildLPS(pat);
        int i = 0, j = 0;
        int n = txt.length(), m = pat.length();
        while (i < n) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++; j++;
                if (j == m) return true; // match
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return false;
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        String rootSer = serialize(root);
        String subSer = serialize(subRoot);
        return kmpSearch(rootSer, subSer);
    }
}
