class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> uniq;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int need = -(nums[i] + nums[j]);
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), need);
                if (it != nums.end() && *it == need) {
                    uniq.insert({nums[i], nums[j], need});
                }
            }
        }
        return vector<vector<int>>(uniq.begin(), uniq.end());
    }
};
