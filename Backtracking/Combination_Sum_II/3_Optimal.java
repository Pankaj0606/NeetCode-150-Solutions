import java.util.*;

class Solution {
    private void dfs(int start, int[] candidates, int target, List<Integer> cur, List<List<Integer>> ans) {
        if (target == 0) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > target) break; // prune
            cur.add(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i], cur, ans);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        dfs(0, candidates, target, new ArrayList<>(), ans);
        return ans;
    }
}
