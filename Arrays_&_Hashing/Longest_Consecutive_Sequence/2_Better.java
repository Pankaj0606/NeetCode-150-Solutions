import java.util.*;

class Solution {
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        Arrays.sort(nums);
        int best = 1, cur = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) continue; // skip duplicates
            if (nums[i] == nums[i-1] + 1) {
                cur++;
            } else {
                best = Math.max(best, cur);
                cur = 1;
            }
        }
        best = Math.max(best, cur);
        return best;
    }
}
