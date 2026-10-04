#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = static_cast<int>(nums.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // avoid overflow
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
