#include <stack>
using namespace std;

class MinStack {
    stack<long long> st;
    long long minVal;
public:
    MinStack() {}
    void push(int x) {
        if(st.empty()) {
            st.push(x);
            minVal = x;
        } else if(x >= minVal) {
            st.push(x);
        } else {
            st.push(2LL * x - minVal); // encoded value
            minVal = x;
        }
    }
    void pop() {
        if(st.empty()) return;
        long long top = st.top();
        st.pop();
        if(top < minVal) {
            // retrieve previous minimum
            minVal = 2LL * minVal - top;
        }
    }
    int top() {
        long long top = st.top();
        if(top >= minVal) return (int)top;
        else return (int)minVal;
    }
    int getMin() { return (int)minVal; }
};
