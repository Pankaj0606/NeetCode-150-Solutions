#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch == '.') continue;
                int d = ch - '1'; // 0‑based index
                int boxIdx = (i / 3) * 3 + (j / 3);
                if (rows[i][d] || cols[j][d] || boxes[boxIdx][d])
                    return false;
                rows[i][d] = cols[j][d] = boxes[boxIdx][d] = true;
            }
        }
        return true;
    }
};
