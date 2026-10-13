class Solution {
    public int characterReplacement(String s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int[] cnt = new int[26];
            for (int j = i; j < n; j++) {
                cnt[s.charAt(j) - 'A']++;
                int maxFreq = 0;
                for (int c = 0; c < 26; c++) {
                    maxFreq = Math.max(maxFreq, cnt[c]);
                }
                int len = j - i + 1;
                if (len - maxFreq <= 1) ans = Math.max(ans, len);
            }
        }
        return ans;
    }
}
