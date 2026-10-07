import java.util.*;
class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1; // min in right half
            } else {
                r = mid; // min in left half (including mid)
            }
        }
        return nums[l];
    }
}
