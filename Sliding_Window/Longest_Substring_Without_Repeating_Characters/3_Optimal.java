class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastIdx = new HashMap<>();
        int maxLen = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            if (lastIdx.containsKey(c) && lastIdx.get(c) >= left) {
                left = lastIdx.get(c) + 1;
            }
            lastIdx.put(c, right);
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}
