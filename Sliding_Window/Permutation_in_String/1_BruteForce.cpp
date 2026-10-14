#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> target(26, 0);
        for (char c : s1) target[c - 'a']++;
        for (int i = 0; i <= m - n; ++i) {
            vector<int> window(26, 0);
            for (int j = 0; j < n; ++j) {
                window[s2[i + j] - 'a']++;
            }
            if (window == target) return true;
        }
        return false;
    }
};
