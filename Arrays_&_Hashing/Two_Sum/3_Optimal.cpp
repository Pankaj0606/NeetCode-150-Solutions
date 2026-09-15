#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx;
        idx.reserve(nums.size());
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = idx.find(complement);
            if (it != idx.end()) {
                return {it->second, i};
            }
            idx[nums[i]] = i; // store after checking to avoid using same element twice
        }
        return {};
    }
};
