#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int best = 1;
        for (int i = 0; i < n; ++i) {
            int cur = 1;
            int next = nums[i] + 1;
            // Linear scan for the next consecutive numbers
            while (true) {
                bool found = false;
                for (int j = 0; j < n; ++j) {
                    if (nums[j] == next) {
                        found = true;
                        ++cur;
                        ++next;
                        break;
                    }
                }
                if (!found) break;
            }
            best = max(best, cur);
        }
        return best;
    }
};
