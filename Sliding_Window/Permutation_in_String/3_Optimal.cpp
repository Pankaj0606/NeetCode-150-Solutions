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
        int matches = 0;
        for (int i = 0; i < 26; ++i) if (cnt[i] == 0) ++matches;
        int left = 0;
        for (int right = 0; right < m; ++right) {
            int idx = s2[right] - 'a';
            cnt[idx]--;
            if (cnt[idx] == 0) ++matches;
            else if (cnt[idx] == -1) --matches;
            if (right - left + 1 > n) {
                int lidx = s2[left] - 'a';
                if (cnt[lidx] == 0) --matches;
                else if (cnt[lidx] == 1) ++matches;
                cnt[lidx]++;
                ++left;
            }
            if (matches == 26) return true;
        }
        return false;
    }
};
