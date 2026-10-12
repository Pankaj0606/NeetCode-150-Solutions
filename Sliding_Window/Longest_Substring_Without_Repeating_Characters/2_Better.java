class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> window = new HashSet<>();
        int left = 0, right = 0, maxLen = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            if (!window.contains(c)) {
                window.add(c);
                right++;
                maxLen = Math.max(maxLen, right - left);
            } else {
                window.remove(s.charAt(left));
                left++;
            }
        }
        return maxLen;
    }
}
