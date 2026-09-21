public class Solution {
    public boolean isValidSudoku(char[][] board) {
        // rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                for (int k = j + 1; k < 9; k++) {
                    if (board[i][j] == board[i][k]) return false;
                }
            }
        }
        // columns
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                for (int k = i + 1; k < 9; k++) {
                    if (board[i][j] == board[k][j]) return false;
                }
            }
        }
        // 3x3 sub‑boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                for (int i = 0; i < 9; i++) {
                    int r1 = boxRow * 3 + i / 3;
                    int c1 = boxCol * 3 + i % 3;
                    if (board[r1][c1] == '.') continue;
                    for (int j = i + 1; j < 9; j++) {
                        int r2 = boxRow * 3 + j / 3;
                        int c2 = boxCol * 3 + j % 3;
                        if (board[r1][c1] == board[r2][c2]) return false;
                    }
                }
            }
        }
        return true;
    }
}
