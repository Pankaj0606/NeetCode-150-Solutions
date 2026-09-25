import java.util.*;

class Solution {
    public int evalRPN(String[] tokens) {
        // Brute‑force: collapse the first operator found each iteration.
        List<String> list = new ArrayList<>(Arrays.asList(tokens));
        while (list.size() > 1) {
            int opIdx = -1;
            for (int i = 0; i < list.size(); i++) {
                String t = list.get(i);
                if (t.equals("+") || t.equals("-") || t.equals("*") || t.equals("/")) {
                    opIdx = i;
                    break;
                }
            }
            int a = Integer.parseInt(list.get(opIdx - 2));
            int b = Integer.parseInt(list.get(opIdx - 1));
            int res = 0;
            String op = list.get(opIdx);
            switch (op) {
                case "+": res = a + b; break;
                case "-": res = a - b; break;
                case "*": res = a * b; break;
                case "/": res = a / b; break; // truncates toward zero
            }
            // replace three tokens with result
            list.set(opIdx - 2, Integer.toString(res));
            // remove the two now‑redundant tokens
            list.remove(opIdx - 1);
            list.remove(opIdx - 1); // after previous removal, the next token shifts left
        }
        return Integer.parseInt(list.get(0));
    }
}
