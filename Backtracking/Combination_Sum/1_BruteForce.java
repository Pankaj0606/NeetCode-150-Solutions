import java.util.*;
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        dfs(candidates, target, 0, cur, res);
        return res;
    }
    private void dfs(int[] cand, int target, int idx, List<Integer> cur, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }
        if (target < 0) return;
        for (int i = 0; i < cand.length; i++) {
            cur.add(cand[i]);
            dfs(cand, target - cand[i], i, cur, res);
            cur.remove(cur.size() - 1);
        }
    }
}
