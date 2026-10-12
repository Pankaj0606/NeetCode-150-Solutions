class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0, maxLen = 0, n = s.size();
        while (right < n) {
            if (!window.count(s[right])) {
                window.insert(s[right]);
                ++right;
                maxLen = max(maxLen, right - left);
            } else {
                window.erase(s[left]);
                ++left;
            }
        }
        return maxLen;
    }
};
