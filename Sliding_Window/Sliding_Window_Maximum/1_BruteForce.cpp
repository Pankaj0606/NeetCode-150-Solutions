class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i <= n - k; ++i) {
            int mx = nums[i];
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] > mx) mx = nums[j];
            }
            res.push_back(mx);
        }
        return res;
    }
};
