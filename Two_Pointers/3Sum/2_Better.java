class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        Set<List<Integer>> uniq = new HashSet<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int need = -(nums[i] + nums[j]);
                int idx = Arrays.binarySearch(nums, j + 1, n, need);
                if (idx > j) {
                    uniq.add(Arrays.asList(nums[i], nums[j], need));
                }
            }
        }
        return new ArrayList<>(uniq);
    }
}
