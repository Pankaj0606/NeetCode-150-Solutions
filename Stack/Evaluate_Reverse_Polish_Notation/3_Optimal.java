import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        // Use a plain int array as a stack to avoid boxing overhead.
        int[] stack = new int[tokens.length];
        int top = 0; // next free position
        for (String tok : tokens) {
            if (tok.length() == 1 && (tok.charAt(0) == '+' || tok.charAt(0) == '-' || tok.charAt(0) == '*' || tok.charAt(0) == '/')) {
                int b = stack[--top];
                int a = stack[--top];
                int res;
                switch (tok.charAt(0)) {
                    case '+': res = a + b; break;
                    case '-': res = a - b; break;
                    case '*': res = a * b; break;
                    default:  res = a / b; break; // '/'
                }
                stack[top++] = res;
            } else {
                stack[top++] = Integer.parseInt(tok);
            }
        }
        return stack[0];
    }
}
