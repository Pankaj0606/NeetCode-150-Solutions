class Solution {
    public int minEatingSpeed(int[] piles, int H) {
        int lo = 1;
        int hi = 0;
        for (int p : piles) hi = Math.max(hi, p);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // ceil(p / mid)
                if (hours > H) break; // early exit
            }
            if (hours <= H) {
                hi = mid; // feasible, try smaller
            } else {
                lo = mid + 1; // not feasible
            }
        }
        return lo;
    }
}
