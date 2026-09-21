#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int d = ch - '1'; // 0‑based
                int mask = 1 << d;
                int boxIdx = (i / 3) * 3 + (j / 3);
                if ((rows[i] & mask) || (cols[j] & mask) || (boxes[boxIdx] & mask))
                    return false;
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[boxIdx] |= mask;
            }
        }
        return true;
    }
};
