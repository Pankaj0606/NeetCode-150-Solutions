#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (const string& w : words) {
            if (exist(board, w)) ans.push_back(w);
        }
        return ans;
    }
private:
    bool exist(vector<vector<char>>& board, const string& word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (dfs(board, word, 0, i, j, vis)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int idx, int i, int j, vector<vector<bool>>& vis) {
        if (idx == (int)word.size()) return true;
        int m = board.size();
        int n = board[0].size();
        if (i<0||j<0||i>=m||j>=n||vis[i][j]||board[i][j]!=word[idx]) return false;
        vis[i][j] = true;
        static const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d: dirs) {
            if (dfs(board, word, idx+1, i+d[0], j+d[1], vis)) return true;
        }
        vis[i][j] = false;
        return false;
    }
};
