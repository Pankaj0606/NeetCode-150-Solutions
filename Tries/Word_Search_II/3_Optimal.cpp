#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26]{};
    string word; // empty if not end of a word
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
            node->word = w;
        }
        return root;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans) {
        char c = board[i][j];
        if (c == '#' || !node->child[c-'a']) return;
        node = node->child[c-'a'];
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word.clear(); // prevent duplicate entries
        }
        board[i][j] = '#';
        static const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = board.size();
        int n = board[0].size();
        for (auto &d: dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni>=0 && nj>=0 && ni<m && nj<n) dfs(board, ni, nj, node, ans);
        }
        board[i][j] = c;
        // Prune leaf nodes to speed up future searches
        bool leaf = true;
        for (int k=0;k<26;++k) if (node->child[k]) { leaf = false; break; }
        if (leaf) {
            delete node; // free memory (optional in interview)
            // Note: parent pointer already lost; safe because we never revisit this path again.
        }
    }
};
