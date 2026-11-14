#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    unordered_map<int, vector<string>> bucket; // length -> words
    WordDictionary() {}
    void addWord(string word) {
        bucket[word.size()].push_back(move(word));
    }
    bool search(string word) {
        int len = word.size();
        auto it = bucket.find(len);
        if (it == bucket.end()) return false;
        for (const string &w : it->second) {
            if (match(w, word)) return true;
        }
        return false;
    }
private:
    bool match(const string &w, const string &pattern) {
        for (size_t i = 0; i < w.size(); ++i) {
            if (pattern[i] != '.' && w[i] != pattern[i]) return false;
        }
        return true;
    }
};
