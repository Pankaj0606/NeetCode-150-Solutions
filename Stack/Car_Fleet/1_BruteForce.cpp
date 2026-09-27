#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n==0) return 0;
        vector<double> time(n);
        for (int i=0;i<n;++i) time[i] = (double)(target - position[i]) / speed[i];
        vector<bool> merged(n,false);
        int fleets = 0;
        for (int i=0;i<n;++i) {
            if (merged[i]) continue;
            fleets++;
            for (int j=0;j<n;++j) {
                if (i==j || merged[j]) continue;
                // car j is ahead of i?
                if (position[j] > position[i] && time[j] <= time[i]) {
                    merged[j] = true; // i catches j before target
                }
            }
        }
        return fleets;
    }
};
