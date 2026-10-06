#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // ceil(p / mid)
                if (hours > H) break; // early exit
            }
            if (hours <= H) {
                hi = mid; // mid works, try smaller
            } else {
                lo = mid + 1; // mid too small
            }
        }
        return lo;
    }
};
