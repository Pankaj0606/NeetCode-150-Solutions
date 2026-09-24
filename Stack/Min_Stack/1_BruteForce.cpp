#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> st;
public:
    MinStack() {}
    void push(int x) { st.push(x); }
    void pop() { if(!st.empty()) st.pop(); }
    int top() { return st.top(); }
    int getMin() {
        int mn = INT_MAX;
        stack<int> temp = st;
        while(!temp.empty()) {
            mn = min(mn, temp.top());
            temp.pop();
        }
        return mn;
    }
};
