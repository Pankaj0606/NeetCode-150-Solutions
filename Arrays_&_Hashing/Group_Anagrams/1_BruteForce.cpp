#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res;
        vector<bool> used(n,false);
        for(int i=0;i<n;++i){
            if(used[i]) continue;
            vector<string> group;
            group.push_back(strs[i]);
            used[i]=true;
            for(int j=i+1;j<n;++j){
                if(!used[j] && isAnagram(strs[i], strs[j])){
                    group.push_back(strs[j]);
                    used[j]=true;
                }
            }
            res.push_back(move(group));
        }
        return res;
    }
private:
    bool isAnagram(const string& a, const string& b){
        if(a.size()!=b.size()) return false;
        int cnt[26]={0};
        for(char c:a) cnt[c-'a']++;
        for(char c:b) cnt[c-'a']--;
        for(int x:cnt) if(x!=0) return false;
        return true;
    }
};
