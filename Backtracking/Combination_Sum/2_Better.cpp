#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
private:
    void backtrack(vector<int>& cand, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < (int)cand.size() && cand[i] <= target; ++i) {
            cur.push_back(cand[i]);
            backtrack(cand, target - cand[i], i, cur, res);
            cur.pop_back();
        }
    }
};
