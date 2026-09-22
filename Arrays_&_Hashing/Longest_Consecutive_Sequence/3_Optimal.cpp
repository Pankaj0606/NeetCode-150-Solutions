#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;
        for (int x : s) {
            // only start counting if x-1 is not in the set
            if (!s.count(x - 1)) {
                int cur = 1;
                int y = x + 1;
                while (s.count(y)) {
                    ++cur;
                    ++y;
                }
                best = max(best, cur);
            }
        }
        return best;
    }
};
