import java.util.Stack;

public class MinStack {
    private Stack<Integer> stack;
    public MinStack() {
        stack = new Stack<>();
    }
    public void push(int x) {
        stack.push(x);
    }
    public void pop() {
        if(!stack.isEmpty()) stack.pop();
    }
    public int top() {
        return stack.peek();
    }
    public int getMin() {
        int min = Integer.MAX_VALUE;
        for(int val : stack) {
            if(val < min) min = val;
        }
        return min;
    }
}
