#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n: nums) freq[n]++;
        vector<pair<int,int>> vec;
        for(auto &p: freq) vec.push_back({p.second,p.first});
        sort(vec.begin(), vec.end(), greater<pair<int,int>>());
        vector<int> result;
        for(int i=0;i<k;i++) result.push_back(vec[i].second);
        return result;
    }
};
