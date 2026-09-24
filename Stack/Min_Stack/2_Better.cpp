#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {}
    void push(int x) {
        st.push(x);
        if(minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }
    void pop() {
        if(st.empty()) return;
        if(st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};
