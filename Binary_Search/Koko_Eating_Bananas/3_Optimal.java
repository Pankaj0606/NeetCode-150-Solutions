class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        long total = 0;
        int max = 0;
        for (int p : piles) {
            total += p;
            max = Math.max(max, p);
        }
        int lo = Math.max(1, (int)((total + H - 1) / H)); // ceil(total / H)
        int hi = max;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid;
                if (hours > H) break;
            }
            if (hours <= H) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
