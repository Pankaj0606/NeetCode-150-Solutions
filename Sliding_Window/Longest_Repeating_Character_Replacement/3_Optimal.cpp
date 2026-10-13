class Solution {
public:
    int characterReplacement(string s) {
        vector<int> cnt(26,0);
        int left = 0, maxCount = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            maxCount = max(maxCount, ++cnt[s[right]-'A']);
            while (right - left + 1 - maxCount > 1) {
                cnt[s[left]-'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
