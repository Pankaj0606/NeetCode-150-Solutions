#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    // key -> ordered map timestamp -> value
    unordered_map<string, map<int, string>> store;

    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value; // O(log N)
    }

    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        const auto &m = store[key];
        auto it = m.upper_bound(timestamp); // first > timestamp
        if (it == m.begin()) return "";   // all timestamps > query
        --it; // now it->first <= timestamp
        return it->second;
    }
};
