import java.util.*;

class Solution {
    private void dfs(int idx, int[] candidates, int target, List<Integer> path, List<List<Integer>> all) {
        if (target == 0) {
            all.add(new ArrayList<>(path));
            return;
        }
        if (idx == candidates.length || target < 0) return;
        // include
        path.add(candidates[idx]);
        dfs(idx + 1, candidates, target - candidates[idx], path, all);
        path.remove(path.size() - 1);
        // exclude
        dfs(idx + 1, candidates, target, path, all);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> all = new ArrayList<>();
        dfs(0, candidates, target, new ArrayList<>(), all);
        // deduplicate
        Set<List<Integer>> set = new HashSet<>();
        for (List<Integer> comb : all) {
            List<Integer> sorted = new ArrayList<>(comb);
            Collections.sort(sorted);
            set.add(sorted);
        }
        return new ArrayList<>(set);
    }
}
