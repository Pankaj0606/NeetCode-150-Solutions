class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                Set<Character> seen = new HashSet<>();
                boolean dup = false;
                for (int k = i; k <= j; k++) {
                    char c = s.charAt(k);
                    if (seen.contains(c)) { dup = true; break; }
                    seen.add(c);
                }
                if (!dup) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
}
