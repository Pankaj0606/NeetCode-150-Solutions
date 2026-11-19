import java.util.*;
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(0, nums, res);
        return res;
    }
    private void backtrack(int first, int[] nums, List<List<Integer>> res) {
        if (first == nums.length) {
            List<Integer> perm = new ArrayList<>();
            for (int num : nums) perm.add(num);
            res.add(perm);
            return;
        }
        for (int i = first; i < nums.length; i++) {
            swap(nums, first, i);
            backtrack(first + 1, nums, res);
            swap(nums, first, i); // backtrack
        }
    }
    private void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
