#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n && T[j] <= T[i]) {
                if (ans[j] == 0) { // no warmer day ahead of j
                    j = n; // break outer while
                    break;
                }
                j += ans[j]; // jump to the next candidate
            }
            if (j < n) ans[i] = j - i;
        }
        return ans;
    }
};
