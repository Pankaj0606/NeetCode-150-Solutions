#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for (int i=0;i<n;++i) cars[i] = {position[i], speed[i]};
        sort(cars.begin(), cars.end(), [](auto &a, auto &b){return a.first > b.first;}); // farthest first
        int fleets = 0;
        double lastTime = -1.0;
        for (auto &c : cars) {
            double t = (double)(target - c.first) / c.second;
            if (t > lastTime) {
                ++fleets;
                lastTime = t;
            }
        }
        return fleets;
    }
};
