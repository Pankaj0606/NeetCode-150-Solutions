#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        idx.reserve(nums.size());
        // First pass: store value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            idx[nums[i]] = i;
        }
        // Second pass: look for complement
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = idx.find(complement);
            if (it != idx.end() && it->second != i) {
                return {i, it->second};
            }
        }
        return {};
    }
};
