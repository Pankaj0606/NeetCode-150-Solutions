#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> cnt(26, 0);
        for (char c : s1) cnt[c - 'a']++;
        for (int i = 0; i < m; ++i) {
            // add current character to the window
            cnt[s2[i] - 'a']--;
            // remove character that slides out of the window
            if (i >= n) cnt[s2[i - n] - 'a']++;
            // when window size equals n, check equality
            if (i >= n - 1) {
                bool ok = true;
                for (int v : cnt) {
                    if (v != 0) { ok = false; break; }
                }
                if (ok) return true;
            }
        }
        return false;
    }
};
