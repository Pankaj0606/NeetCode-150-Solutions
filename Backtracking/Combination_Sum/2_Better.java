import java.util.*;
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }
    private void backtrack(int[] cand, int target, int start, List<Integer> cur, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < cand.length && cand[i] <= target; i++) {
            cur.add(cand[i]);
            backtrack(cand, target - cand[i], i, cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}
