import java.util.*;
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        if (n == 0) return 0;
        double[] time = new double[n];
        for (int i = 0; i < n; i++) {
            time[i] = (double)(target - position[i]) / speed[i];
        }
        boolean[] merged = new boolean[n];
        int fleets = 0;
        for (int i = 0; i < n; i++) {
            if (merged[i]) continue;
            fleets++;
            for (int j = 0; j < n; j++) {
                if (i == j || merged[j]) continue;
                if (position[j] > position[i] && time[j] <= time[i]) {
                    merged[j] = true; // i catches j
                }
            }
        }
        return fleets;
    }
}
