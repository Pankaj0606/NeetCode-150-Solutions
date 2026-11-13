#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        words.push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        for (const auto& w : words) {
            if (w == word) return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        for (const auto& w : words) {
            if (w.rfind(prefix, 0) == 0) return true; // prefix match
        }
        return false;
    }
private:
    vector<string> words;
};
