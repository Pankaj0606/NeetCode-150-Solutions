class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0, nums, path, result);
        return result;
    }
private:
    void backtrack(int index, const vector<int>& nums, vector<int>& path, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(path);
            return;
        }
        // exclude
        backtrack(index + 1, nums, path, result);
        // include
        path.push_back(nums[index]);
        backtrack(index + 1, nums, path, result);
        path.pop_back();
    }
};
