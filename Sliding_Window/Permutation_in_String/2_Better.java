import java.util.*;

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;
        int[] cnt = new int[26];
        for (char c : s1.toCharArray()) cnt[c - 'a']++;
        for (int i = 0; i < m; i++) {
            cnt[s2.charAt(i) - 'a']--;
            if (i >= n) cnt[s2.charAt(i - n) - 'a']++;
            if (i >= n - 1) {
                boolean ok = true;
                for (int v : cnt) {
                    if (v != 0) { ok = false; break; }
                }
                if (ok) return true;
            }
        }
        return false;
    }
}
