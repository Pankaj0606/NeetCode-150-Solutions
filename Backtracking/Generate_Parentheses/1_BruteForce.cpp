class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current(2 * n, ' ');
        backtrack(0, current, result, n);
        return result;
    }

private:
    void backtrack(int pos, string& current, vector<string>& result, int n) {
        if (pos == 2 * n) {
            if (isValid(current))
                result.push_back(current);
            return;
        }
        current[pos] = '(';
        backtrack(pos + 1, current, result, n);
        current[pos] = ')';
        backtrack(pos + 1, current, result, n);
    }

    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') ++balance;
            else --balance;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
};
