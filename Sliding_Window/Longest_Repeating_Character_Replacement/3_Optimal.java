class Solution {
    public int characterReplacement(String s) {
        int[] cnt = new int[26];
        int left = 0, maxCount = 0, ans = 0;
        for (int right = 0; right < s.length(); right++) {
            maxCount = Math.max(maxCount, ++cnt[s.charAt(right) - 'A']);
            while (right - left + 1 - maxCount > 1) {
                cnt[s.charAt(left) - 'A']--;
                left++;
            }
            ans = Math.max(ans, right - left + 1);
        }
        return ans;
    }
}
