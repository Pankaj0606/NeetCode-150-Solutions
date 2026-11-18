#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int idx, const vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& all) {
        if (target == 0) {
            all.push_back(path);
            return;
        }
        if (idx == (int)candidates.size() || target < 0) return;
        // include current element
        path.push_back(candidates[idx]);
        dfs(idx + 1, candidates, target - candidates[idx], path, all);
        path.pop_back();
        // exclude current element
        dfs(idx + 1, candidates, target, path, all);
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        vector<vector<int>> all;
        vector<int> path;
        dfs(0, candidates, target, path, all);
        // deduplicate using set
        set<vector<int>> uniq;
        for (auto &vec : all) {
            vector<int> sortedVec = vec;
            sort(sortedVec.begin(), sortedVec.end());
            uniq.insert(sortedVec);
        }
        vector<vector<int>> ans(uniq.begin(), uniq.end());
        return ans;
    }
};
