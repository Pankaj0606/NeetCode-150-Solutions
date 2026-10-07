#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for (int v : nums) ans = min(ans, v);
        return ans;
    }
};
