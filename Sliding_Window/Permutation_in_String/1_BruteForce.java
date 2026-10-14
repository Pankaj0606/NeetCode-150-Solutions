import java.util.*;

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;
        int[] target = new int[26];
        for (char c : s1.toCharArray()) target[c - 'a']++;
        for (int i = 0; i <= m - n; i++) {
            int[] window = new int[26];
            for (int j = 0; j < n; j++) {
                window[s2.charAt(i + j) - 'a']++;
            }
            if (Arrays.equals(window, target)) return true;
        }
        return false;
    }
}
