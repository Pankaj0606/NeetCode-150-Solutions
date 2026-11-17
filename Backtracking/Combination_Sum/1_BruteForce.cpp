#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, 0, cur, res);
        return res;
    }
private:
    void dfs(vector<int>& cand, int target, int idx, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0) return;
        for (int i = 0; i < (int)cand.size(); ++i) {
            cur.push_back(cand[i]);
            dfs(cand, target - cand[i], i, cur, res);
            cur.pop_back();
        }
    }
};
