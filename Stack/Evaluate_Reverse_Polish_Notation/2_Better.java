import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new ArrayDeque<>();
        for (String tok : tokens) {
            if (tok.equals("+") || tok.equals("-") || tok.equals("*") || tok.equals("/")) {
                int b = stack.pop();
                int a = stack.pop();
                int res;
                switch (tok) {
                    case "+": res = a + b; break;
                    case "-": res = a - b; break;
                    case "*": res = a * b; break;
                    default:    res = a / b; break; // '/'
                }
                stack.push(res);
            } else {
                stack.push(Integer.parseInt(tok));
            }
        }
        return stack.pop();
    }
}
