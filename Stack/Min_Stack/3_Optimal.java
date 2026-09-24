import java.util.Stack;

public class MinStack {
    private Stack<Long> stack;
    private long min;
    public MinStack() {
        stack = new Stack<>();
    }
    public void push(int x) {
        if(stack.isEmpty()) {
            stack.push((long)x);
            min = x;
        } else if(x >= min) {
            stack.push((long)x);
        } else {
            // encode previous min
            stack.push(2L * x - min);
            min = x;
        }
    }
    public void pop() {
        if(stack.isEmpty()) return;
        long top = stack.pop();
        if(top < min) {
            // retrieve previous min
            min = 2L * min - top;
        }
    }
    public int top() {
        long top = stack.peek();
        if(top >= min) return (int)top;
        else return (int)min;
    }
    public int getMin() {
        return (int)min;
    }
}
