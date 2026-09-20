#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                prod *= nums[j];
            }
            ans[i] = static_cast<int>(prod);
        }
        return ans;
    }
};
