#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    // key -> vector of (timestamp, value) – timestamps are strictly increasing
    unordered_map<string, vector<pair<int, string>>> store;

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value}); // O(1)
    }

    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        const auto &vec = store[key];
        int l = 0, r = (int)vec.size() - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans == -1 ? "" : vec[ans].second;
    }
};
