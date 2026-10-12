class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_set<char> seen;
                bool dup = false;
                for (int k = i; k <= j; ++k) {
                    if (seen.count(s[k])) { dup = true; break; }
                    seen.insert(s[k]);
                }
                if (!dup) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
