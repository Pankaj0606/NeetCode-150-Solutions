#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> st; // indices with decreasing temperatures
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && T[st.top()] <= T[i]) st.pop();
            if (!st.empty()) ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
