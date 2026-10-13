class Solution {
    public int characterReplacement(String s) {
        int[] cnt = new int[26];
        int left = 0, ans = 0;
        for (int right = 0; right < s.length(); right++) {
            cnt[s.charAt(right) - 'A']++;
            int maxFreq = 0;
            for (int c = 0; c < 26; c++) maxFreq = Math.max(maxFreq, cnt[c]);
            while (right - left + 1 - maxFreq > 1) {
                cnt[s.charAt(left) - 'A']--;
                left++;
                maxFreq = 0;
                for (int c = 0; c < 26; c++) maxFreq = Math.max(maxFreq, cnt[c]);
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}
