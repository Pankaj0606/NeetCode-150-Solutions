#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> dll; // front = most recent
    unordered_map<int,int> mp; // key -> value (fast existence)
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        auto itVal = mp.find(key);
        if (itVal == mp.end()) return -1;
        // Linear search in list to move node to front (O(N))
        for (auto it = dll.begin(); it != dll.end(); ++it) {
            if (it->first == key) {
                int val = it->second;
                dll.erase(it);
                dll.push_front({key, val});
                return val;
            }
        }
        return -1; // should not reach
    }
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists: remove its node (O(N))
            for (auto it = dll.begin(); it != dll.end(); ++it) {
                if (it->first == key) { dll.erase(it); break; }
            }
        } else if ((int)dll.size() == cap) {
            // Evict LRU
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        mp[key] = value;
    }
};
