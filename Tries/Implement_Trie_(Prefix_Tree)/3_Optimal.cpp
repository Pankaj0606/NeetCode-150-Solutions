#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        bool isEnd = false;
        Node* child[26] = {nullptr};
    };
public:
    Trie() { root = new Node(); }
    
    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) node->child[idx] = new Node();
            node = node->child[idx];
        }
        node->isEnd = true;
    }
    
    bool search(const string& word) const {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(const string& prefix) const {
        Node* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
        }
        return true;
    }
private:
    Node* root;
};
