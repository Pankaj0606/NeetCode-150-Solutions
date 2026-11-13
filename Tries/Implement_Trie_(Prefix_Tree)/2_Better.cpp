#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        bool isEnd = false;
        unordered_map<char, Node*> child;
    };
public:
    Trie() { root = new Node(); }
    
    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->child.count(c)) node->child[c] = new Node();
            node = node->child[c];
        }
        node->isEnd = true;
    }
    
    bool search(const string& word) const {
        Node* node = root;
        for (char c : word) {
            if (!node->child.count(c)) return false;
            node = node->child.at(c);
        }
        return node->isEnd;
    }
    
    bool startsWith(const string& prefix) const {
        Node* node = root;
        for (char c : prefix) {
            if (!node->child.count(c)) return false;
            node = node->child.at(c);
        }
        return true;
    }
private:
    Node* root;
};
