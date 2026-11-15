import java.util.*;

class TrieNode {
    TrieNode[] child = new TrieNode[26];
    String word = null; // non‑null if a word ends here
}

public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        TrieNode root = buildTrie(words);
        List<String> ans = new ArrayList<>();
        int m = board.length, n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }

    private TrieNode buildTrie(String[] words) {
        TrieNode root = new TrieNode();
        for (String w : words) {
            TrieNode node = root;
            for (char c : w.toCharArray()) {
                int idx = c - 'a';
                if (node.child[idx] == null) node.child[idx] = new TrieNode();
                node = node.child[idx];
            }
            node.word = w; // mark end of word
        }
        return root;
    }

    private void dfs(char[][] board, int i, int j, TrieNode node, List<String> ans) {
        char c = board[i][j];
        if (c == '#' || node.child[c - 'a'] == null) return;
        node = node.child[c - 'a'];
        if (node.word != null) {
            ans.add(node.word);
            // In the "better" version we keep the word for possible future finds
        }
        board[i][j] = '#'; // mark visited
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int[] d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.length && nj < board[0].length) {
                dfs(board, ni, nj, node, ans);
            }
        }
        board[i][j] = c; // restore
    }
}
