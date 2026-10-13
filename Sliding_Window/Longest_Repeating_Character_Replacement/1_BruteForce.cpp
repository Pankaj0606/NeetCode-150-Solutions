class Solution {
public:
    int characterReplacement(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26,0);
            for (int j = i; j < n; ++j) {
                cnt[s[j]-'A']++;
                int maxFreq = 0;
                for (int c = 0; c < 26; ++c) maxFreq = max(maxFreq, cnt[c]);
                int len = j - i + 1;
                if (len - maxFreq <= 1) ans = max(ans, len);
            }
        }
        return ans;
    }
};
