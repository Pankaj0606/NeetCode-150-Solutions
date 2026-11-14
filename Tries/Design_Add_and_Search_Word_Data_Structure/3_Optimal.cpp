#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isEnd = false;
    TrieNode* child[26] = {};
    ~TrieNode() {
        for (auto &c : child) if (c) delete c;
    }
};

class WordDictionary {
public:
    WordDictionary() { root = new TrieNode(); }
    ~WordDictionary() { delete root; }
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->child[idx]) node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    TrieNode* root;
    bool dfs(const string &word, int pos, TrieNode* node) {
        if (!node) return false;
        if (pos == (int)word.size()) return node->isEnd;
        char ch = word[pos];
        if (ch == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(word, pos + 1, node->child[i])) return true;
            }
            return false;
        } else {
            return dfs(word, pos + 1, node->child[ch - 'a']);
        }
    }
};
