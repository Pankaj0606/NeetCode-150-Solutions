class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] res = new int[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            int mx = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] > mx) mx = nums[j];
            }
            res[i] = mx;
        }
        return res;
    }
}
