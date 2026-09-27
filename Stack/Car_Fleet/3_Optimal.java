import java.util.*;
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        int[][] cars = new int[n][2];
        for (int i = 0; i < n; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        // sort by position descending (farther from target first)
        Arrays.sort(cars, (a, b) -> b[0] - a[0]);
        int fleets = 0;
        double lastTime = -1.0;
        for (int[] car : cars) {
            double t = (double)(target - car[0]) / car[1];
            if (t > lastTime) {
                fleets++;
                lastTime = t;
            }
        }
        return fleets;
    }
}
