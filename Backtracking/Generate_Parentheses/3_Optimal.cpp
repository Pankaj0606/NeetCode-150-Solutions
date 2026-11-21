class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack("", n, n, result);
        return result;
    }

private:
    void backtrack(string current, int open, int close, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        if (open > 0) backtrack(current + "(", open - 1, close, result);
        if (close > open) backtrack(current + ")", open, close - 1, result);
    }
};
