import java.util.*;
class Solution {
    public int findMin(int[] nums) {
        int ans = nums[0];
        for (int v : nums) ans = Math.min(ans, v);
        return ans;
    }
}
