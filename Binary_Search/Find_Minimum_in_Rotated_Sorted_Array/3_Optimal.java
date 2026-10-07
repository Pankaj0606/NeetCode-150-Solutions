import java.util.*;
class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            if (nums[l] < nums[r]) return nums[l]; // sorted subarray
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l]) {
                l = mid + 1; // left side sorted, go right
            } else {
                r = mid; // right side unsorted, keep mid
            }
        }
        return nums[l];
    }
}
