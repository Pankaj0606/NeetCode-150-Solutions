import java.util.*;
class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] ans = new int[n];
        Deque<Integer> stack = new ArrayDeque<>(); // stores indices with decreasing temps
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && T[stack.peek()] <= T[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                ans[i] = stack.peek() - i;
            }
            stack.push(i);
        }
        return ans;
    }
}
