#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> dll; // front = most recent
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key -> node iterator
public:
    LRUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        // Move accessed node to front
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second; // value
    }
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            // Update value and move to front
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }
        // Evict if needed
        if ((int)dll.size() == cap) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }
        // Insert new node at front
        dll.emplace_front(key, value);
        mp[key] = dll.begin();
    }
};
