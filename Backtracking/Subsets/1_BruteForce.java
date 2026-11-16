class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(0, nums, new ArrayList<>(), result);
        return result;
    }
    private void backtrack(int index, int[] nums, List<Integer> path, List<List<Integer>> result) {
        if (index == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }
        // exclude
        backtrack(index + 1, nums, path, result);
        // include
        path.add(nums[index]);
        backtrack(index + 1, nums, path, result);
        path.remove(path.size() - 1);
    }
}
