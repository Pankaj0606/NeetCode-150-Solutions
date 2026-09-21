public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxes = new int[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int d = ch - '1'; // 0‑based
                int mask = 1 << d;
                int boxIdx = (i / 3) * 3 + (j / 3);
                if ((rows[i] & mask) != 0 || (cols[j] & mask) != 0 || (boxes[boxIdx] & mask) != 0)
                    return false;
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        return true;
    }
}
