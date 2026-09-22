import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int best = 1;
        for (int i = 0; i < n; i++) {
            int cur = 1;
            int next = nums[i] + 1;
            while (true) {
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (nums[j] == next) {
                        found = true;
                        cur++;
                        next++;
                        break;
                    }
                }
                if (!found) break;
            }
            best = Math.max(best, cur);
        }
        return best;
    }
}
