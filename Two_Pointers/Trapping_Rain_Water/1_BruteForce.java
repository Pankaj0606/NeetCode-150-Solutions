class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = 0, rightMax = 0;
            for (int l = i; l >= 0; l--) leftMax = Math.max(leftMax, height[l]);
            for (int r = i; r < n; r++) rightMax = Math.max(rightMax, height[r]);
            ans += Math.min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
}
