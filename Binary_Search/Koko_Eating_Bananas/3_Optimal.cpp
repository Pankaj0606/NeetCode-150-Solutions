#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long total = 0;
        int maxPile = 0;
        for (int p : piles) {
            total += p;
            maxPile = max(maxPile, p);
        }
        int lo = max(1, (int)((total + H - 1) / H)); // ceil(total / H)
        int hi = maxPile;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid;
                if (hours > H) break;
            }
            if (hours <= H) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
