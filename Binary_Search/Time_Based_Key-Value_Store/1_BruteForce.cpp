#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    // key -> list of (timestamp, value) in insertion order
    unordered_map<string, vector<pair<int, string>>> store;

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        const auto &vec = store[key];
        // Linear scan from the end (worst‑case O(N))
        for (int i = (int)vec.size() - 1; i >= 0; --i) {
            if (vec[i].first <= timestamp) return vec[i].second;
        }
        return "";
    }
};
