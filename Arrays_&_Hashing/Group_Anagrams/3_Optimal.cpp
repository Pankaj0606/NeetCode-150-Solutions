#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const string& s: strs){
            int cnt[26] = {0};
            for(char c: s) cnt[c-'a']++;
            // Build a compact key like "#1#0#2..."
            string key;
            key.reserve(52);
            for(int i=0;i<26;++i){
                key.push_back('#');
                key.append(to_string(cnt[i]));
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(mp.size());
        for(auto &p: mp) res.push_back(move(p.second));
        return res;
    }
};
