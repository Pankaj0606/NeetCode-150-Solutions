#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int left_max = 0, right_max = 0;
            for (int l = i; l >= 0; --l) left_max = max(left_max, height[l]);
            for (int r = i; r < n; ++r) right_max = max(right_max, height[r]);
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
    }
};
