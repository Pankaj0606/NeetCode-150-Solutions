class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIdx;
        int maxLen = 0, left = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            if (lastIdx.find(c) != lastIdx.end() && lastIdx[c] >= left) {
                left = lastIdx[c] + 1;
            }
            lastIdx[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
