class Solution {
public:
    int characterReplacement(string s) {
        vector<int> cnt(26,0);
        int left = 0, ans = 0;
        for (int right = 0; right < (int)s.size(); ++right) {
            cnt[s[right]-'A']++;
            int maxFreq = 0;
            for (int c = 0; c < 26; ++c) maxFreq = max(maxFreq, cnt[c]);
            while (right - left + 1 - maxFreq > 1) {
                cnt[s[left]-'A']--;
                left++;
                maxFreq = 0;
                for (int c = 0; c < 26; ++c) maxFreq = max(maxFreq, cnt[c]);
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
