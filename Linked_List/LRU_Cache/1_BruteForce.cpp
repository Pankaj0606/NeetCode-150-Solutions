#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    vector<pair<int,int>> items; // {key,value}, front = most recent
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].first == key) {
                int val = items[i].second;
                items.erase(items.begin() + i);
                items.insert(items.begin(), {key, val});
                return val;
            }
        }
        return -1;
    }
    void put(int key, int value) {
        // Remove existing key if present
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].first == key) {
                items.erase(items.begin() + i);
                break;
            }
        }
        // Evict least recent if at capacity
        if ((int)items.size() == cap) {
            items.pop_back();
        }
        items.insert(items.begin(), {key, value});
    }
};
