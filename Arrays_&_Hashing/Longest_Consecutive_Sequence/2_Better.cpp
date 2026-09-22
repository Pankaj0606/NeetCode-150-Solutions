#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int best = 1, cur = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue; // skip duplicates
            if (nums[i] == nums[i-1] + 1) {
                ++cur;
            } else {
                best = max(best, cur);
                cur = 1;
            }
        }
        best = max(best, cur);
        return best;
    }
};
