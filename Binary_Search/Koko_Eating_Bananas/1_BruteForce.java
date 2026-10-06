class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int max = 0;
        for (int p : piles) max = Math.max(max, p);
        for (int K = 1; K <= max; K++) {
            int hours = 0;
            for (int p : piles) {
                hours += (p + K - 1) / K; // ceil(p / K)
            }
            if (hours <= H) return K;
        }
        return max; // fallback
    }
}
