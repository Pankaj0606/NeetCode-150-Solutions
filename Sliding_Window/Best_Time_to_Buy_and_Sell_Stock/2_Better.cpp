#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> minPrice(n);
        minPrice[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice[i] = min(minPrice[i - 1], prices[i]);
        }
        int maxProfit = 0;
        for (int i = 1; i < n; ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice[i - 1]);
        }
        return maxProfit;
    }
};
