#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int maxPile = *max_element(piles.begin(), piles.end());
        for (int K = 1; K <= maxPile; ++K) {
            int hours = 0;
            for (int p : piles) {
                hours += (p + K - 1) / K; // ceil(p / K)
            }
            if (hours <= H) return K;
        }
        return maxPile; // fallback (should never reach here)
    }
};
