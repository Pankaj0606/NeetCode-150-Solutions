#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<bool> visited(t.size(), false);
        for (char c : s) {
            bool found = false;
            for (size_t i = 0; i < t.size(); ++i) {
                if (!visited[i] && t[i] == c) {
                    visited[i] = true;
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
};
