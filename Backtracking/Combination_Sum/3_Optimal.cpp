#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        dfs(candidates, target, 0, path, ans);
        return ans;
    }
private:
    void dfs(const vector<int>& cand, int remain, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (remain == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = start; i < (int)cand.size() && cand[i] <= remain; ++i) {
            path.push_back(cand[i]);
            dfs(cand, remain - cand[i], i, path, ans);
            path.pop_back();
        }
    }
};
