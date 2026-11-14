#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    vector<string> words;
    WordDictionary() {}
    void addWord(string word) {
        words.push_back(move(word));
    }
    bool search(string word) {
        for (const string &w : words) {
            if (match(w, word)) return true;
        }
        return false;
    }
private:
    bool match(const string &w, const string &pattern) {
        if (w.size() != pattern.size()) return false;
        for (size_t i = 0; i < w.size(); ++i) {
            if (pattern[i] != '.' && w[i] != pattern[i]) return false;
        }
        return true;
    }
};
