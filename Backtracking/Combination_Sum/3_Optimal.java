import java.util.*;
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        dfs(candidates, target, 0, new ArrayList<>(), ans);
        return ans;
    }
    private void dfs(int[] cand, int remain, int start, List<Integer> path, List<List<Integer>> ans) {
        if (remain == 0) {
            ans.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i < cand.length && cand[i] <= remain; i++) {
            path.add(cand[i]);
            dfs(cand, remain - cand[i], i, path, ans);
            path.remove(path.size() - 1);
        }
    }
}
