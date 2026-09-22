import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) set.add(num);
        int best = 0;
        for (int x : set) {
            if (!set.contains(x - 1)) { // start of a sequence
                int cur = 1;
                int y = x + 1;
                while (set.contains(y)) {
                    cur++;
                    y++;
                }
                best = Math.max(best, cur);
            }
        }
        return best;
    }
}
