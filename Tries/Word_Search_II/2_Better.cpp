#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26]{};
    string word; // non‑empty if a word ends here
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
private:
    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->child[idx]) node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = w; // mark end of word
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans) {
        char c = board[i][j];
        if (c == '#' || !node->child[c-'a']) return;
        node = node->child[c-'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            // **Do NOT delete** node->word here – this is the "better" version
        }
        board[i][j] = '#'; // mark visited
        static const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = board.size();
        int n = board[0].size();
        for (auto &d: dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni>=0 && nj>=0 && ni<m && nj<n) dfs(board, ni, nj, node, ans);
        }
        board[i][j] = c; // restore
    }
};
