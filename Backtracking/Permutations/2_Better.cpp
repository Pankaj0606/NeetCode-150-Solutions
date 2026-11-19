#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int> nums) {
        vector<vector<int>> res;
        backtrack(0, nums, res);
        return res;
    }
private:
    void backtrack(int first, vector<int>& nums, vector<vector<int>>& res) {
        if (first == (int)nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = first; i < (int)nums.size(); ++i) {
            swap(nums[first], nums[i]);
            backtrack(first + 1, nums, res);
            swap(nums[first], nums[i]); // backtrack
        }
    }
};
