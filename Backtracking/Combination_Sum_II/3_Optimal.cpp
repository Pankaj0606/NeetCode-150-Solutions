#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int start, const vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i-1]) continue; // skip duplicates
            if (candidates[i] > target) break; // prune because array is sorted
            cur.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i], cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(0, candidates, target, cur, ans);
        return ans;
    }
};
