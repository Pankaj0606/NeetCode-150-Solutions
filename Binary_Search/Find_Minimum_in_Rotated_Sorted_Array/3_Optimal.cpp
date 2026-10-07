#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;
        while (l < r) {
            if (nums[l] < nums[r]) return nums[l]; // already sorted subarray
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[l]) {
                // left part sorted, min must be right of mid
                l = mid + 1;
            } else {
                // right part unsorted, min is at mid or left of it
                r = mid;
            }
        }
        return nums[l];
    }
};
