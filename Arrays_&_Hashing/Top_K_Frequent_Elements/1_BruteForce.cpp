#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n: nums) freq[n]++;
        vector<int> result;
        for(int i=0;i<k;i++){
            int maxFreq=0, candidate=0;
            for(auto &p: freq){
                if(p.second>maxFreq){
                    maxFreq=p.second;
                    candidate=p.first;
                }
            }
            result.push_back(candidate);
            freq.erase(candidate);
        }
        return result;
    }
};
