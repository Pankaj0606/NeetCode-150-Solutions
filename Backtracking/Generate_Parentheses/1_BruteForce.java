class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        char[] current = new char[2 * n];
        backtrack(0, current, result, n);
        return result;
    }

    private void backtrack(int pos, char[] current, List<String> result, int n) {
        if (pos == 2 * n) {
            if (isValid(current))
                result.add(new String(current));
            return;
        }
        current[pos] = '(';
        backtrack(pos + 1, current, result, n);
        current[pos] = ')';
        backtrack(pos + 1, current, result, n);
    }

    private boolean isValid(char[] s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
}
