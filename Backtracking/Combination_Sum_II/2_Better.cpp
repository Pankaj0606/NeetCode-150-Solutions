#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, const vector<int>& candidates, int target, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            if (candidates[i] > target) break; // early stop
            cur.push_back(candidates[i]);
            backtrack(i + 1, candidates, target - candidates[i], cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(0, candidates, target, cur, res);
        // post‑process to remove duplicates
        set<vector<int>> uniq(res.begin(), res.end());
        return vector<vector<int>>(uniq.begin(), uniq.end());
    }
};
