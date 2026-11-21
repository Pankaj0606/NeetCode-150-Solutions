class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack("", n, n, result);
        return result;
    }

    private void backtrack(String current, int open, int close, List<String> result) {
        if (open == 0 && close == 0) {
            result.add(current);
            return;
        }
        if (open > 0) backtrack(current + "(", open - 1, close, result);
        if (close > open) backtrack(current + ")", open, close - 1, result);
    }
}
