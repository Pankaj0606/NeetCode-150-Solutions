import java.util.*;

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        if (n > m) return false;
        int[] cnt = new int[26];
        for (char c : s1.toCharArray()) cnt[c - 'a']++;
        int matches = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] == 0) matches++;
        int left = 0;
        for (int right = 0; right < m; right++) {
            int idx = s2.charAt(right) - 'a';
            cnt[idx]--;
            if (cnt[idx] == 0) matches++;
            else if (cnt[idx] == -1) matches--;
            if (right - left + 1 > n) {
                int lidx = s2.charAt(left) - 'a';
                if (cnt[lidx] == 0) matches--;
                else if (cnt[lidx] == 1) matches++;
                cnt[lidx]++;
                left++;
            }
            if (matches == 26) return true;
        }
        return false;
    }
}
