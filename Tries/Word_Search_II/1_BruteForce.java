import java.util.*;

public class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> ans = new ArrayList<>();
        for (String w : words) {
            if (exist(board, w)) ans.add(w);
        }
        return ans;
    }

    private boolean exist(char[][] board, String word) {
        int m = board.length, n = board[0].length;
        boolean[][] vis = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, 0, i, j, vis)) return true;
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int idx, int i, int j, boolean[][] vis) {
        if (idx == word.length()) return true;
        int m = board.length, n = board[0].length;
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || board[i][j] != word.charAt(idx)) return false;
        vis[i][j] = true;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int[] d : dirs) {
            if (dfs(board, word, idx+1, i+d[0], j+d[1], vis)) return true;
        }
        vis[i][j] = false;
        return false;
    }
}
