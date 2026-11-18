import java.util.*;

class Solution {
    private void backtrack(int start, int[] candidates, int target, List<Integer> cur, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > target) break; // prune
            cur.add(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], cur, res);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, candidates, target, new ArrayList<>(), res);
        // remove duplicates post‑processing
        Set<List<Integer>> set = new HashSet<>(res);
        return new ArrayList<>(set);
    }
}
