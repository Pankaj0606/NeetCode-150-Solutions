class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        int[] minPrice = new int[n];
        minPrice[0] = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice[i] = Math.min(minPrice[i - 1], prices[i]);
        }
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice[i - 1]);
        }
        return maxProfit;
    }
}
