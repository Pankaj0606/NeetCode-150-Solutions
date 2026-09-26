import java.util.*;
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] ans = new int[n];
        for (int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && T[j] <= T[i]) {
                if (ans[j] == 0) { // no warmer day after j
                    j = n; // break loop
                    break;
                }
                j += ans[j]; // jump ahead
            }
            if (j < n) ans[i] = j - i;
        }
        return ans;
    }
}
